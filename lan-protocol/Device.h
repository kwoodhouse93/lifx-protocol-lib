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
    Device(uint64_t targetMacAddress)
         : m_target(targetMacAddress) {}

    // Find devices without needing access to a specific target
    static void GetService (DevicePayload::GetService payload);
    static Device& StateService();

    // Get messages
    void GetHostInfo        (DevicePayload::GetHostInfo     payload, bool ack_required = 0);
    void GetHostFirmware    (DevicePayload::GetHostFirmware payload, bool ack_required = 0);
    void GetWifiInfo        (DevicePayload::GetWifiInfo     payload, bool ack_required = 0);
    void GetWifiFirmware    (DevicePayload::GetWifiFirmware payload, bool ack_required = 0);
    void GetPower           (DevicePayload::GetPower        payload, bool ack_required = 0);
    void GetLabel           (DevicePayload::GetLabel        payload, bool ack_required = 0);
    void GetVersion         (DevicePayload::GetVersion      payload, bool ack_required = 0);
    void GetInfo            (DevicePayload::GetInfo         payload, bool ack_required = 0);
    void GetLocation        (DevicePayload::GetLocation     payload, bool ack_required = 0);
    void GetGroup           (DevicePayload::GetGroup        payload, bool ack_required = 0);

    // Set messages
    void SetPower (DevicePayload::SetPower payload, bool ack_required = 0, bool res_required = 1);
    void SetLabel (DevicePayload::SetLabel payload, bool ack_required = 0, bool res_required = 1);

    // State messages
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
    DevicePayload::Acknowledgement Acknowledgement();

    // Echo messages
    void EchoRequest (const DevicePayload::EchoRequest &payload, bool ack_required = 0);
    DevicePayload::EchoResponse EchoResponse();

private:
    //TODO: Add type for representing device characteristics
    DevicePayload::StateService m_stateService;
    uint64_t    m_target;

#define _DEBUG_
#ifdef _DEBUG_
public:
    inline void SetStateService(uint8_t service, DevicePayload::port_t port)
    {
        m_stateService.service = service;
        m_stateService.port = port;
    }
#endif
};

#endif // DEVICE_H
