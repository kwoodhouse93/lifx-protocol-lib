#ifndef MESSAGE_H
#define MESSAGE_H

#include "Payload.h"

// For debugging
#include <bitset>

#include <inttypes.h>
#include <ostream>

class Message
{
public:
    Message();

    void SetFrame(bool tagged);
    void SetFrameAddress(uint64_t target, bool ack_required, bool res_required);
    void SetProtocolHeader(uint16_t type);
    void SetPayload(const Payload& payload);

    std::string Encode();

    void Send();

private:

    // Known values for all messages
    static const uint8_t    c_origin      =    0;
    static const bool       c_addressable =    1;
    static const uint16_t   c_protocol    = 1024;

    // Assuming reserved values should all be set to 0.
    // The value should be implicitly converted to the
    // appropriate type when used to set a header value.
    static const int        c_reserved    =    0;

    // Header components            // Bits (Total: 288 bits)

    struct Frame {                  // 64 bits:
        uint16_t    size;           //   16
        uint8_t     origin;         //    2
        bool        tagged;         //    1
        bool        addressable;    //    1
        uint16_t    protocol;       //   12
        uint32_t    source;         //   32

        friend std::ostream& operator<< (std::ostream& os, const Frame& frame)
        {
            uint64_t wrapper = 0;
            wrapper = wrapper
                    | ( (uint64_t)frame.size        << 48)
                    | (((uint64_t)frame.origin & 3) << 46)
                    | ( (uint64_t)frame.tagged      << 45)
                    | ( (uint64_t)frame.addressable << 44)
                    | ( (uint64_t)frame.protocol    << 32)
                    | ( (uint64_t)frame.source);
            os << wrapper;
//            os << std::bitset<64>(wrapper); << std::endl;
//            os << std::bitset<16>(frame.size)       //<< "."
//               << std::bitset<2>(frame.origin)      //<< "."
//               << frame.tagged                      //<< "."
//               << frame.addressable                 //<< "."
//               << std::bitset<12>(frame.protocol)   //<< "."
//               << std::bitset<32>(frame.source) << std::endl;
            return os;
        }
    };

    struct FrameAddress {           // 128 bits:
        uint64_t    target;         //   64
        uint8_t     reserved0[6];   //   48
        uint8_t     reserved1;      //    6
        bool        ack_required;   //    1
        bool        res_required;   //    1
        uint8_t     sequence;       //    8

        friend std::ostream& operator<< (std::ostream& os, const FrameAddress& frameAddress)
        {
            uint64_t wrapper1 = 0, wrapper0 = 0;
            wrapper1 = frameAddress.target;
            wrapper0 = wrapper0
                     | ( (uint64_t)frameAddress.reserved0[5]    << 56)
                     | ( (uint64_t)frameAddress.reserved0[4]    << 48)
                     | ( (uint64_t)frameAddress.reserved0[3]    << 40)
                     | ( (uint64_t)frameAddress.reserved0[2]    << 32)
                     | ( (uint64_t)frameAddress.reserved0[1]    << 24)
                     | ( (uint64_t)frameAddress.reserved0[0]    << 16)
                     | (((uint64_t)frameAddress.reserved1 & 63) << 10)
                     | ( (uint64_t)frameAddress.ack_required    <<  9)
                     | ( (uint64_t)frameAddress.res_required    <<  8)
                     | ( (uint64_t)frameAddress.sequence);
            os << wrapper1 << wrapper0;
            return os;
        }
    };

    struct ProtocolHeader {         // 96 bits:
        uint64_t    reserved2;      //   64
        uint16_t    type;           //   16
        uint16_t    reserved3;      //   16

        friend std::ostream& operator<< (std::ostream& os, const ProtocolHeader& protocolHeader)
        {
            uint64_t wrapper1 = 0;
            uint32_t wrapper0 = 0;
            wrapper1 = protocolHeader.reserved2;
            wrapper0 = wrapper0
                     | ((uint32_t)protocolHeader.type << 16)
                     | ((uint32_t)protocolHeader.reserved3);
            os << wrapper1 << wrapper0;
            return os;
        }
    };

    Frame           m_frame;
    FrameAddress    m_frameAddress;
    ProtocolHeader  m_protocolHeader;
    Payload*        m_payload;

};

#endif // MESSAGE_H
