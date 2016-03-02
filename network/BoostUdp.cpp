#include "BoostUdp.h"

BoostUdp::~BoostUdp()
{
    m_socket.close();
}

void BoostUdp::Send (const std::string& message)
{
    m_socket.send_to(boost::asio::buffer(message, message.size()), m_endpoint);
}
