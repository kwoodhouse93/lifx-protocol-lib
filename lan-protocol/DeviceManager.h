#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "Device.h"

class DeviceManager
{
public:
    DeviceManager();

    // Find devices on network and return number found.
    int FindDevices();

    Device& GetDevice(/*identifier or index*/) const;

    // Manually manage devices
    bool AddDevice(uint8_t* macAddress);
    bool RemoveDevice(/*identifier*/);

private:
    // Container for Device objects

};

#endif // DEVICEMANAGER_H
