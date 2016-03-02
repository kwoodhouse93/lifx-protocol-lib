#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <inttypes.h>

// Common payload components (currently empty)
struct Payload
{
    virtual ~Payload() =0;
};

namespace DeviceMessage
{

// Enumerations
enum Service {
    UDP                 = 1,
};

enum DeviceMessage {
    GetService          = 2,
    StateService        = 3,
    GetHostInfo         = 12,
    StateHostInfo       = 13,
    GetHostFirmware     = 14,
    StateHostFirmware   = 15,
    GetWifiInfo         = 16,
    StateWifiInfo       = 17,
    GetWifiFirmware     = 18,
    StateWifiFirmware   = 19,
    GetPower            = 20,
    SetPower            = 21,
    StatePower          = 22,
    GetLabel            = 23,
    SetLabel            = 24,
    StateLabel          = 25,
    GetVersion          = 32,
    StateVersion        = 33,
    GetInfo             = 34,
    StateInfo           = 35,
    Acknowledgement     = 45,
    GetLocation         = 48,
    StateLocation       = 50,
    GetGroup            = 51,
    StateGroup          = 53,
    EchoRequest         = 58,
    EchoResponse        = 59
};

// Data types
typedef char        label_t[32];
typedef uint32_t    port_t;
typedef uint16_t    level_t;
typedef uint64_t    time_t;

// Device message payloads
struct GetService : public Payload
{
};

struct StateService : public Payload
{
    uint8_t     service;
    port_t      port;
};

struct GetHostInfo : public Payload
{
};

struct StateHostInfo : public Payload
{
    float       signal;
    uint32_t    tx;
    uint32_t    rx;
    int16_t     reserved0;
};

struct GetHostFirmware : public Payload
{
};

struct StateHostFirmware : public Payload
{
    uint64_t    build;
    uint64_t    reserved0;
    uint32_t    version;
};

struct GetWifiInfo : public Payload
{
};

struct StateWifiInfo : public Payload
{
    float       signal;
    uint32_t    tx;
    uint32_t    rx;
    int16_t     reserved0;
};

struct GetPower : public Payload
{
};

struct SetPower : public Payload
{
    level_t     level;
};

struct StatePower : public Payload
{
    level_t     level;
};

struct GetLabel : public Payload
{
};

struct SetLabel : public Payload
{
    label_t     label;
};

struct StateLabel : public Payload
{
    label_t     label;
};

struct GetVersion : public Payload
{
};

struct StateVersion : public Payload
{
    uint32_t    vendor;
    uint32_t    product;
    uint32_t    version;
};

struct GetInfo : public Payload
{
};

struct StateInfo : public Payload
{
    time_t      time;
    uint64_t    uptime;
    uint64_t    downtime;
};

struct Acknowledgement : public Payload
{
};

struct GetLocation : public Payload
{
};

struct StateLocation : public Payload
{
    uint8_t     location[16];
    label_t     label;
    uint64_t    updated_at;
};

struct GetGroup : public Payload
{
};

struct StateGroup : public Payload
{
    uint8_t     group[16];
    label_t     label;
    uint64_t    update_at;
};

struct EchoRequest : public Payload
{
    uint8_t     payload[64];
};

struct EchoResponse : public Payload
{
    uint8_t     payload[64];
};

} // namespace DeviceMessage

#endif // PAYLOAD_H
