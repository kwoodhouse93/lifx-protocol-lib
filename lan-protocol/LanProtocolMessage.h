#ifndef LANPROTOCOLMESSAGE_H
#define LANPROTOCOLMESSAGE_H

#include <inttypes.h>

class LanProtocolMessage
{
public:
    LanProtocolMessage();

private:
    struct Message {
        Frame           frame;
        FrameAddress    frameAdderss;
        ProtocolHeader  protocolHeader;
        Payload         payload;
    };

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
        uint64_t    reserved;       // 64
        uint16_t    type;           // 16
        uint16_t    reserved;       // 16
    };
};

#endif // LANPROTOCOLMESSAGE_H
