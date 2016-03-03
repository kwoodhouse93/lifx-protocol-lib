#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <inttypes.h>
#include <ostream>

// Common payload components (currently empty)
struct Payload
{
    virtual ~Payload(){};

    friend std::ostream& operator<< (std::ostream& os, const Payload& payload)
    {
        (void)payload;
        return os;
    }
};

namespace DevicePayload
{

// Enumerations
enum Service {
    UDP = 1,
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

    friend std::ostream& operator<< (std::ostream& os, const StateService& payload)
    {
        os << payload.service
           << payload.port;
        return os;
    }
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

    friend std::ostream& operator<< (std::ostream& os, const StateHostInfo& payload)
    {
        os << payload.signal
           << payload.tx
           << payload.rx
           << payload.reserved0;
        return os;
    }
};

struct GetHostFirmware : public DevicePayload
{
};

struct StateHostFirmware : public DevicePayload
{
    uint64_t    build;
    uint64_t    reserved0;
    uint32_t    version;

    friend std::ostream& operator<< (std::ostream& os, const StateHostFirmware& payload)
    {
        os << payload.build
           << payload.reserved0
           << payload.version;
        return os;
    }
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

    friend std::ostream& operator<< (std::ostream& os, const StateWifiInfo& payload)
    {
        os << payload.signal
           << payload.tx
           << payload.rx
           << payload.reserved0;
        return os;
    }
};

struct GetWifiFirmware : public DevicePayload
{
};

struct StateWifiFirmware : public DevicePayload
{
    uint64_t    build;
    uint64_t    reserved0;
    uint32_t    version;

    friend std::ostream& operator<< (std::ostream& os, const StateWifiFirmware& payload)
    {
        os << payload.build
           << payload.reserved0
           << payload.version;
        return os;
    }
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

    friend std::ostream& operator<< (std::ostream& os, const StatePower& payload)
    {
        os << payload.level;
        return os;
    }
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

    friend std::ostream& operator<< (std::ostream& os, const StateLabel& payload)
    {
        //TODO: test proper output of label payload (not null-terminated).
        os << payload.label;
        return os;
    }
};

struct GetVersion : public DevicePayload
{
};

struct StateVersion : public DevicePayload
{
    uint32_t    vendor;
    uint32_t    product;
    uint32_t    version;

    friend std::ostream& operator<< (std::ostream& os, const StateVersion& payload)
    {
        os << payload.vendor
           << payload.product
           << payload.version;
        return os;
    }
};

struct GetInfo : public DevicePayload
{
};

struct StateInfo : public DevicePayload
{
    time_t      time;
    uint64_t    uptime;
    uint64_t    downtime;

    friend std::ostream& operator<< (std::ostream& os, const StateInfo& payload)
    {
        os << payload.time
           << payload.uptime
           << payload.downtime;
        return os;
    }
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

    friend std::ostream& operator<< (std::ostream& os, const StateLocation& payload)
    {
        os << payload.location
           << payload.label
           << payload.updated_at;
        return os;
    }
};

struct GetGroup : public DevicePayload
{
};

struct StateGroup : public DevicePayload
{
    uint8_t     group[16];
    label_t     label;
    uint64_t    updated_at;

    friend std::ostream& operator<< (std::ostream& os, const StateGroup& payload)
    {
        os << payload.group
           << payload.label
           << payload.updated_at;
        return os;
    }
};

struct EchoRequest : public DevicePayload
{
    uint8_t     payload[64];
};

struct EchoResponse : public DevicePayload
{
    uint8_t     payload[64];

    friend std::ostream& operator<< (std::ostream& os, const EchoResponse& payload)
    {
        os << payload.payload;
        return os;
    }
};

} // namespace DevicePayload

#endif // PAYLOAD_H
