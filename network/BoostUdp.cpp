#include "BoostUdp.h"

BoostUdp::~BoostUdp()
{
    m_socket.close();
}

void BoostUdp::Send (const std::string& message)
{
    m_socket.send_to(boost::asio::buffer(message, message.size()), m_endpoint);
}

std::string BoostUdp::Receive()
{
    char buffer[MaxLength];
    m_socket.receive_from(boost::asio::buffer(buffer, MaxLength), m_endpoint);
    return std::string(buffer);
}
