#ifndef SYSINFO_H
#define SYSINFO_H


class SysInfo
{
public:

    static SysInfo& instance();
    virtual ~SysInfo();

    SysInfo(const SysInfo& rhs) = delete;
    SysInfo& operator=(const SysInfo& rhs) = delete;

    virtual void init() = 0;

    virtual double cpuLoadAverage() = 0;
    virtual double memoryUsed() = 0;

protected:

    explicit SysInfo();
};

#endif // SYSINFO_H
