#ifndef DEVICE_H
#define DEVICE_H

#include "Payload.h"

class Device
{
public:
    enum DeviceMessage {
        getService          = 2,
        gtateService        = 3,
        getHostInfo         = 12,
        stateHostInfo       = 13,
        getHostFirmware     = 14,
        stateHostFirmware   = 15,
        getWifiInfo         = 16,
        stateWifiInfo       = 17,
        getWifiFirmware     = 18,
        stateWifiFirmware   = 19,
        getPower            = 20,
        setPower            = 21,
        statePower          = 22,
        getLabel            = 23,
        setLabel            = 24,
        stateLabel          = 25,
        getVersion          = 32,
        stateVersion        = 33,
        getInfo             = 34,
        stateInfo           = 35,
        acknowledgement     = 45,
        getLocation         = 48,
        stateLocation       = 50,
        getGroup            = 51,
        stateGroup          = 53,
        echoRequest         = 58,
        echoResponse        = 59
    };

    Device();

    // Get messages
    void GetService         (DevicePayload::GetService      payload);
    void GetHostInfo        (DevicePayload::GetHostInfo     payload);
    void GetHostFirmware    (DevicePayload::GetHostFirmware payload);
    void GetWifiInfo        (DevicePayload::GetWifiInfo     payload);
    void GetWifiFirmware    (DevicePayload::GetWifiFirmware payload);
    void GetPower           (DevicePayload::GetPower        payload);
    void GetLabel           (DevicePayload::GetLabel        payload);
    void GetVersion         (DevicePayload::GetVersion      payload);
    void GetInfo            (DevicePayload::GetInfo         payload);
    void GetLocation        (DevicePayload::GetLocation     payload);
    void GetGroup           (DevicePayload::GetGroup        payload);

    // Set messages
    void SetPower           (DevicePayload::SetPower        payload);
    void SetLabel           (DevicePayload::SetLabel        payload);

    // State messages
    DevicePayload::StateService         StateService();
    DevicePayload::StateHostInfo        StateHostInfo();
    DevicePayload::StateHostFirmware    StateHostFirmware();
    DevicePayload::StateWifiInfo        StateWifiInfo();
    DevicePayload::StateWifiFirmware    StateWifiFirmware();
    DevicePayload::StatePower           StatePower();
    DevicePayload::StateLabel           StateLabel();
    DevicePayload::StateVersion         StateVersion();
    DevicePayload::StateInfo            StateInfo();
    DevicePayload::StateLocation        StateLocation();
    DevicePayload::StateGroup           StateGroup();

    // Ack message
    DevicePayload::Acknowledgement      Acknowledgement();

    // Echo messages
    void EchoRequest        (const DevicePayload::EchoRequest &payload);
    DevicePayload::EchoResponse         EchoResponse();

private:
    //TODO: Add type for representing device characteristics
    uint64_t    m_target;
    bool        m_ack_required;
    bool        m_res_required;
};

#endif // DEVICE_H
