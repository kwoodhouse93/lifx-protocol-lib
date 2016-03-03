#include "Device.h"

#include "Message.h"

Device::Device()
{

}

void Device::GetService(DevicePayload::GetService payload)
{
    Message message;

    message.SetFrame(1);
    message.SetFrameAddress(0, 0, 0);
    message.SetProtocolHeader(getService);
    message.SetPayload(payload);

    message.Send();
}

void Device::EchoRequest(const DevicePayload::EchoRequest& payload)
{
    Message message;

    message.SetFrame(0);
    message.SetFrameAddress(m_target, m_ack_required, m_res_required);
    message.SetProtocolHeader(echoRequest);
    message.SetPayload(payload);

    message.Send();
}
