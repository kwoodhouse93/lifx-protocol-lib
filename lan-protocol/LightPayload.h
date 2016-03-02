#ifndef LIGHTPAYLOAD_H
#define LIGHTPAYLOAD_H

#include "Payload.h"

#include <inttypes.h>

namespace LightMessage
{

// Enumerations
enum LightMessage {
    Get                 = 101,
    SetColor            = 102,
    State               = 107,
    GetPower            = 116,
    SetPower            = 117,
    StatePower          = 118,
};

// Data types
struct HSBK
{
    uint16_t hue;
    uint16_t saturation;
    uint16_t brightness;
    uint16_t kelvin;
};

struct LightPayload : public Payload
{
};

struct Get : public LightPayload
{
};

struct SetColor : public LightPayload
{
    uint8_t     reserved0;
    HSBK        color;
    uint32_t    duration;
};

struct State : public LightPayload
{
    HSBK        color;
    int16_t     reserved0;
    uint16_t    power;
    char        label[32];
    uint64_t    reserved1;
};

struct GetPower : public LightPayload
{
};

struct SetPower : public LightPayload
{
    uint16_t    level;
    uint32_t    duration;
};

struct StatePower : public LightPayload
{
    uint16_t    level;
};

} // namespace LightMessage

#endif // LIGHTPAYLOAD_H
