#ifndef NETWORKBOOST_H
#define NETWORKBOOST_H

#include "BoostUdp.h"
#include "Network.h"

#include <boost/asio.hpp>
#include <string>

// Debugging
#include <iostream>

class NetworkBoost : public Network
{
public:
    NetworkBoost(const std::string& host, const std::string& port)
              : Network(host, port)
    {
#ifdef _DEBUG_
        std::cout << "Constructing NetworkBoost" << std::endl;
#endif

        m_ios = new boost::asio::io_service();
        m_boostUdp = new BoostUdp(*m_ios, m_host, m_port);
    }

    ~NetworkBoost()
    {
        delete m_ios;
        delete m_boostUdp;
    }

    void Send(const std::string& message);
    std::string Receive();

private:
    BoostUdp* m_boostUdp;
    boost::asio::io_service* m_ios;
};

#endif // NETWORKBOOST_H
