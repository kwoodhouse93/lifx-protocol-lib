#ifndef MESSAGE_H
#define MESSAGE_H

#include <inttypes.h>

class Message
{
public:
    Message();

private:

    // Header components            // Bits
    struct Frame {
        uint16_t    size;           // 16
        uint8_t     origin;         //  2
        bool        tagged;         //  1
        bool        addressable;    //  1
        uint16_t    protocol;       // 12
        uint32_t    source;         // 32
    };

    struct FrameAddress {
        uint64_t    target;         // 64
        uint8_t     reserved0[6];   // 48
        uint8_t     reserved1;      //  6
        bool        ack_required;   //  1
        bool        res_required;   //  1
        uint8_t     sequence;       //  8
    };

    struct ProtocolHeader {
        uint64_t    reserved2;       // 64
        uint16_t    type;           // 16
        uint16_t    reserved3;       // 16
    };

    Frame m_frame;
    FrameAddress m_frameAddress;
    ProtocolHeader m_ProtocolHeader;

};

#endif // MESSAGE_H
