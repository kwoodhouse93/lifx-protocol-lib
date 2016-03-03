#include "lan-protocol/Device.h"
#include "network/BoostUdp.h"

#include <boost/asio.hpp>

int main (int argc, char* argv[])
{
    (void)argc; (void)argv;

    DevicePayload::GetService payload;
    Device::GetService(payload);
//    boost::asio::io_service ios;
//    BoostUdp client (ios, "localhost", "1337");

//    client.Send("Hello world\r\n");

    return 0;
}
