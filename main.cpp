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

    return 0;
}
