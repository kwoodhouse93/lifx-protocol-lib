#include "NetworkBoost.h"

void NetworkBoost::Send(const std::string& message)
{
    m_boostUdp->Send(message);
}

std::string NetworkBoost::Receive()
{
    std::string buffer;
    buffer = m_boostUdp->Receive();
    return buffer;
}
