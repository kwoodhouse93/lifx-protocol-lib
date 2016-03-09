#define _DEBUG_

#include "lan-protocol/Device.h"

#include <boost/asio.hpp>

// Debugging
#include <iostream>

int main (int argc, char* argv[])
{
    (void)argc; (void)argv;

    DevicePayload::GetService payload;
    Device::GetService(payload);

#ifdef _DEBUG_
    Device device;
    device.SetStateService(DevicePayload::UDP, 56700);

    DevicePayload::EchoRequest echoPl;
    for (int i = 0; i < 64; i++)
        echoPl.payload[i] = i;

    device.EchoRequest(echoPl);

    DevicePayload::GetHostInfo getHostInfoPayload;
    device.GetHostInfo(getHostInfoPayload);

    DevicePayload::GetHostFirmware getHostFirmwarePayload;
    device.GetHostFirmware(getHostFirmwarePayload);

    DevicePayload::GetWifiInfo getWifiInfoPayload;
    device.GetWifiInfo(getWifiInfoPayload);

    DevicePayload::GetWifiFirmware getWifiFirmwarePayload;
    device.GetWifiFirmware(getWifiFirmwarePayload);

    DevicePayload::GetPower getPowerPayload;
    device.GetPower(getPowerPayload);

    DevicePayload::GetLabel getLabelPayload;
    device.GetLabel(getLabelPayload);

    DevicePayload::GetVersion getVersionPayload;
    device.GetVersion(getVersionPayload);

    DevicePayload::GetInfo getInfoPayload;
    device.GetInfo(getInfoPayload);

    DevicePayload::GetLocation getLocationPayload;
    device.GetLocation(getLocationPayload);

    DevicePayload::GetGroup getGroupPayload;
    device.GetGroup(getGroupPayload);
#endif

    return 0;
}
