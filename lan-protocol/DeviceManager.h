#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "Device.h"

#include <boost/ptr_container/ptr_vector.hpp>

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
    boost::ptr_vector<Device> m_deviceList;

    // Make this a system configuration value?
    // Time in seconds
    const int c_findDeviceTimeout = 5;
};

#endif // DEVICEMANAGER_H
