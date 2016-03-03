#ifndef MESSAGE_H
#define MESSAGE_H

#include "Payload.h"

#include <inttypes.h>
#include <string>

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
    struct Frame {                  //
        uint16_t    size;           //   16
        uint8_t     origin;         //    2
        bool        tagged;         //    1
        bool        addressable;    //    1
        uint16_t    protocol;       //   12
        uint32_t    source;         //   32
    };                              // ====
                                    //   64
    struct FrameAddress {           //
        uint64_t    target;         //   64
        uint8_t     reserved0[6];   //   48
        uint8_t     reserved1;      //    6
        bool        ack_required;   //    1
        bool        res_required;   //    1
        uint8_t     sequence;       //    8
    };                              // ====
                                    //  128
    struct ProtocolHeader {         //
        uint64_t    reserved2;      //   64
        uint16_t    type;           //   16
        uint16_t    reserved3;      //   16
    };                              // ====
                                    //   96
    Frame           m_frame;
    FrameAddress    m_frameAddress;
    ProtocolHeader  m_protocolHeader;
    Payload*        m_payload;

};

#endif // MESSAGE_H
