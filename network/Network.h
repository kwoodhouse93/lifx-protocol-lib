#ifndef NETWORK_H
#define NETWORK_H

#include <string>

// Debugging
#include <iostream>

class Network
{
public:
    Network(const std::string& host,
            const std::string& port)
          : m_host (host),
            m_port (port)
    {
        std::cout << "Constructing Network" << std::endl;
        m_host = host;
        m_port = port;
    }
    virtual ~Network() {}

    virtual void Send(const std::string& message) =0;
    virtual std::string Receive() =0;

protected:
    std::string m_host;
    std::string m_port;
};

#endif // NETWORK_H
