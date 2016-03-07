#ifndef BOOSTUDP_H
#define BOOSTUDP_H

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <string>

using boost::asio::ip::udp;

class BoostUdp
{
public:
    BoostUdp(boost::asio::io_service& ioservice,
            const std::string& host,
            const std::string& port)
          : m_ioservice (ioservice),
            m_socket    (ioservice, udp::endpoint(udp::v4(), 0))
    {
        udp::resolver           resolver(m_ioservice);
        udp::resolver::query    query(udp::v4(), host, port);
        udp::resolver::iterator iter = resolver.resolve(query);
        m_endpoint = *iter;
    }

    ~BoostUdp();

    void Send (const std::string& message);
    std::string Receive();

private:
    static const int MaxLength = 512;

    boost::asio::io_service& m_ioservice;
    udp::socket     m_socket;
    udp::endpoint   m_endpoint;

};

#endif // BOOSTUDP_H
