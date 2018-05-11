#include "sysinfowindowsimpl.h"

#include <windows.h>

// Book forgot to include
#include <QtGlobal>

SysInfoWindowsImpl::SysInfoWindowsImpl()
{
}

void SysInfoWindowsImpl::init()
{
}

double SysInfoWindowsImpl::cpuLoadAverage()
{
    return 0.0;
}

double SysInfoWindowsImpl::memoryUsed()
{
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(MEMORYSTATUSEX);

    GlobalMemoryStatusEx(&memoryStatus);

    qulonglong memoryPhysicalUsed =
            memoryStatus.ullTotalPhys -
            memoryStatus.ullAvailPhys;

    return 100.0 * (double) memoryPhysicalUsed /
            (double) memoryStatus.ullTotalPhys;
}
