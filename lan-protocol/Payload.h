#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <inttypes.h>

// Common payload components (currently empty)
struct Payload
{
    virtual ~Payload() =0;
};

namespace DevicePayload
{

// Enumerations
enum Service {
    UDP                 = 1,
};

// Data types
typedef char        label_t[32];
typedef uint32_t    port_t;
typedef uint16_t    level_t;
typedef uint64_t    time_t;

// Fields common to all device payloads (currently none).
struct DevicePayload : public Payload
{
};

// Device message payloads
struct GetService : public DevicePayload
{
};

struct StateService : public DevicePayload
{
    uint8_t     service;
    port_t      port;
};

struct GetHostInfo : public DevicePayload
{
};

struct StateHostInfo : public DevicePayload
{
    float       signal;
    uint32_t    tx;
    uint32_t    rx;
    int16_t     reserved0;
};

struct GetHostFirmware : public DevicePayload
{
};

struct StateHostFirmware : public DevicePayload
{
    uint64_t    build;
    uint64_t    reserved0;
    uint32_t    version;
};

struct GetWifiInfo : public DevicePayload
{
};

struct StateWifiInfo : public DevicePayload
{
    float       signal;
    uint32_t    tx;
    uint32_t    rx;
    int16_t     reserved0;
};

struct GetWifiFirmware : public DevicePayload
{
};

struct StateWifiFirmware : public DevicePayload
{
    uint64_t    build;
    uint64_t    reserved0;
    uint32_t    version;
};

struct GetPower : public DevicePayload
{
};

struct SetPower : public DevicePayload
{
    level_t     level;
};

struct StatePower : public DevicePayload
{
    level_t     level;
};

struct GetLabel : public DevicePayload
{
};

struct SetLabel : public DevicePayload
{
    label_t     label;
};

struct StateLabel : public DevicePayload
{
    label_t     label;
};

struct GetVersion : public DevicePayload
{
};

struct StateVersion : public DevicePayload
{
    uint32_t    vendor;
    uint32_t    product;
    uint32_t    version;
};

struct GetInfo : public DevicePayload
{
};

struct StateInfo : public DevicePayload
{
    time_t      time;
    uint64_t    uptime;
    uint64_t    downtime;
};

struct Acknowledgement : public DevicePayload
{
};

struct GetLocation : public DevicePayload
{
};

struct StateLocation : public DevicePayload
{
    uint8_t     location[16];
    label_t     label;
    uint64_t    updated_at;
};

struct GetGroup : public DevicePayload
{
};

struct StateGroup : public DevicePayload
{
    uint8_t     group[16];
    label_t     label;
    uint64_t    update_at;
};

struct EchoRequest : public DevicePayload
{
    uint8_t     payload[64];
};

struct EchoResponse : public DevicePayload
{
    uint8_t     payload[64];
};

} // namespace DevicePayload

#endif // PAYLOAD_H
