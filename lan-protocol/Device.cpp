#include "Device.h"

#include "Message.h"

// Debugging
#include <iostream>

Device::Device()
{
    m_target = 0;
}

void Device::GetService(const DevicePayload::GetService& payload)
{
#ifdef _DEBUG_
    std::cout << std::endl << "Device::GetService entered with payload: " << payload << std::endl;
#endif

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

#ifdef _DEBUG_
    std::cout << "Message constructed, ready to send: " << message << std::endl;
#endif

    message.Send(port);
}

// This function might need handling differently as we don't just expect one response.
// Maybe we need to define a response window with a timeout and accept all responses
// within that window.  Those responses can then be used to define 'Device' objects in
// a container, which can be used by applications/scripts to access particular devices.
int Device::StateService(boost::ptr_vector<Device>& deviceList, const int& timeout)
{
    (void)timeout;
    deviceList.clear();
    // deviceList.push_back(std::auto_ptr<Device>(new Device));
    return deviceList.size();
}

void Device::GetHostInfo(const DevicePayload::GetHostInfo& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getHostInfo);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
}

void Device::GetHostFirmware(const DevicePayload::GetHostFirmware& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getHostFirmware);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
}

void Device::GetWifiInfo(const DevicePayload::GetWifiInfo& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getWifiInfo);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
}

void Device::GetWifiFirmware(const DevicePayload::GetWifiFirmware& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getWifiFirmware);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
}

void Device::GetPower(const DevicePayload::GetPower& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getPower);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
}

void Device::GetLabel(const DevicePayload::GetLabel& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getLabel);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
}

void Device::GetVersion(const DevicePayload::GetVersion& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getVersion);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
}

void Device::GetInfo(const DevicePayload::GetInfo& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getInfo);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
}

void Device::GetLocation(const DevicePayload::GetLocation& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getLocation);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
}

void Device::GetGroup(const DevicePayload::GetGroup& payload, bool ack_required)
{
    Message message;

    const bool tagged = ((m_target == 0) ? 1 : 0);
    const bool res_required = 1;

    message.SetFrame(tagged);
    message.SetFrameAddress(m_target, ack_required, res_required);
    message.SetProtocolHeader(getGroup);
    message.SetPayload(payload);

    message.Send(m_stateService.port);
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
}

DevicePayload::EchoResponse Device::EchoResponse()
{
    Message message;
    message.Receive();

    DevicePayload::EchoResponse payload;
    return payload;
}
