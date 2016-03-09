#ifndef NETWORKBOOST_H
#define NETWORKBOOST_H

#include "BoostUdp.h"
#include "Network.h"

#include <boost/asio.hpp>
#include <boost/scoped_ptr.hpp>
#include <string>

// Debugging
#include <iostream>

class NetworkBoost : public Network
{
public:
    NetworkBoost(const std::string& host, const std::string& port)
              : Network(host, port),
                m_ios(new boost::asio::io_service()),
                m_boostUdp(new BoostUdp(*m_ios, host, port))
    {
#ifdef _DEBUG_
        std::cout << "Constructing NetworkBoost" << std::endl;
#endif
    }

    void Send(const std::string& message);
    std::string Receive();

private:
    boost::scoped_ptr<boost::asio::io_service> m_ios;
    boost::scoped_ptr<BoostUdp> m_boostUdp;
};

#endif // NETWORKBOOST_H
