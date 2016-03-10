#include "DeviceManager.h"

#include "network/Network.h"

DeviceManager::DeviceManager()
{

}

int DeviceManager::FindDevices()
{
    DevicePayload::GetService payload;
    Device::GetService(payload);

    return Device::StateService(m_deviceList, c_findDeviceTimeout);
}
