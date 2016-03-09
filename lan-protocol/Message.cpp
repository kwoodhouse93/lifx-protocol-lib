#include "Message.h"

#include "network/Network.h"
#include "network/NetworkBoost.h"

#include <algorithm>
#include <boost/scoped_ptr.hpp>

// For debugging purposes
#include <iostream>
#include <sstream>

Message::Message()
{

}

void Message::SetFrame(bool tagged)
{
    m_frame.tagged = tagged;
}

void Message::SetFrameAddress(uint64_t target, bool ack_required, bool res_required)
{
    m_frameAddress.target = target;
    m_frameAddress.ack_required = ack_required;
    m_frameAddress.res_required = res_required;
}

void Message::SetProtocolHeader(uint16_t type)
{
    m_protocolHeader.type = type;
}

void Message::SetPayload(const Payload& payload)
{
    m_payload = const_cast<Payload*>(&payload);
}

// Generate all values and construct message to be sent.
// Note, this assumes all manually set fields have already
// been sent! Future work might try to make this more robust.
std::string Message::Encode()
{
    //TODO: Generate the source in the client then pass it down to here somehow.
    uint32_t source = 0; // e.g. source = GetClient().GetSource();
    //TODO: Generate sequence id
    uint8_t sequence = 0;

 // m_frame.size must be generated last, so is set below.
    m_frame.origin = c_origin;
 // m_frame.tagged is already set.
    m_frame.addressable = c_addressable;
    m_frame.protocol = c_protocol;
    m_frame.source = source;

 // m_frameAddress.target is already set.
    for (int i = 0; i < 6; i++)
        m_frameAddress.reserved0[i] = c_reserved;
    m_frameAddress.reserved1 = c_reserved;
 // m_frameAddress.ack_required is already set.
 // m_frameAddress.res_required is already set.
    m_frameAddress.sequence = sequence;

    m_protocolHeader.reserved2 = c_reserved;
 // m_protocolHeader.type is already set.
    m_protocolHeader.reserved3 = c_reserved;

 // Payload should already exist

    //TODO: Generate size
    m_frame.size = 36 + sizeof(*m_payload);

    //TODO: Create string from structs
    std::stringstream message;

    message << "/"
            << m_frame << "."
            << m_frameAddress << "."
            << m_protocolHeader << "."
            << *m_payload << "/"
            << std::endl;

    return message.str();
}

void Message::Send(const DevicePayload::port_t& port)
{
#ifdef _DEBUG_
    std::cout << std::endl << "Entered Message::Send with port: " << port << std::endl
              << "Ready to encode" << std::endl;
#endif

    std::string message = Encode();

#ifdef _DEBUG_
    std::cout << "Encoded message: " << message << std::endl;

    std::cout << "Constructing string from port number" << std::endl;
#endif

    std::stringstream portStream;
    portStream << port;

#ifdef _DEBUG_
    std::cout << "Port: " << port << ", String: " << portStream.str() <<std::endl;
    std::cout << "Setting up network" << std::endl;
#endif

    boost::scoped_ptr<Network> network(new NetworkBoost("localhost", portStream.str()));

#ifdef _DEBUG_
    std::cout << "Network: " << network << std::endl;
    std::cout << "Ready to send" << std::endl;
#endif
    network->Send(message);
}

void Message::Receive()
{
    // Get from network

}
