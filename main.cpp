#include "lan-protocol/Device.h"

#include <boost/asio.hpp>

// Debugging
#include <iostream>

int main (int argc, char* argv[])
{
    (void)argc; (void)argv;

    DevicePayload::GetService payload;
    std::cout << "Payload constructed, calling Device::GetService" << std::endl;
    Device::GetService(payload);

    Device device;
    device.SetStateService(DevicePayload::UDP, 56700);

    DevicePayload::EchoRequest echoPl;
    for (int i = 0; i < 64; i++)
        echoPl.payload[i] = i;

    device.EchoRequest(echoPl);

    return 0;
}
