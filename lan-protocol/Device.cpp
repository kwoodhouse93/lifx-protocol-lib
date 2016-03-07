#include "Device.h"

#include "Message.h"

// Debugging
#include <iostream>

Device::Device()
{
    m_target = 0;
}

void Device::GetService(DevicePayload::GetService payload)
{
    std::cout << std::endl << "Device::GetService entered with payload: " << payload << std::endl;

    Message message;

    const bool tagged = 1;
    const uint64_t target = 0;
    const bool ack_required = 0;
    const bool res_required = 1;
    const DevicePayload::port_t port = 56700;

    message.SetFrame(tagged);
    message.SetFrameAddress(target, ack_required, res_required);
    message.SetProtocolHeader(getService);
    message.SetPayload(payload);

    std::cout << "Message constructed, ready to send: " << message << std::endl;
    message.Send(port);
}

void Device::EchoRequest(const DevicePayload::EchoRequest& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(echoRequest);
    message.SetPayload(payload);

    message.Send(m_stateService.port);

    EchoResponse();
}

DevicePayload::EchoResponse Device::EchoResponse()
{
    Message message;
    message.Receive();

    DevicePayload::EchoResponse payload;
    return payload;
}
