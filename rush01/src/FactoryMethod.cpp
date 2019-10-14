
#include "FactoryMethod.hpp"

typedef struct s_toCreateModules
{
    std::string     module;
    IMonitorModule *(FactoryMethod::*prt)();
}               t_toCreateModules;

t_toCreateModules FactoryMethod::arrayToCreateModules[] = {{"-os", &FactoryMethod::createOsHostModule},
                                                           {"-dt", &FactoryMethod::createTimeDataModule},
                                                           {"-cpu", &FactoryMethod::createCpuUsageModule},
                                                           {"-ram", &FactoryMethod::createPhysMemModule},
                                                           {"-net", &FactoryMethod::createNetworksModule},
                                                           {"-vm", &FactoryMethod::createVirtualMemModule},
                                                           {"-hd", &FactoryMethod::createDisksModule}}; // Инициализация структуры
FactoryMethod::FactoryMethod() {}
FactoryMethod::~FactoryMethod() {}

IMonitorModule* FactoryMethod::createOsHostModule()
{
    return static_cast<IMonitorModule *>(new OSHostModule());
}

IMonitorModule* FactoryMethod::createTimeDataModule()
{
    return static_cast<IMonitorModule *>(new TimeDateModule());
}

IMonitorModule* FactoryMethod::createCpuUsageModule()
{
    return static_cast<IMonitorModule *>(new CpuUsageModule());
}

IMonitorModule* FactoryMethod::createPhysMemModule()
{
    return static_cast<IMonitorModule *>(new PhysMemModule());
}

IMonitorModule* FactoryMethod::createNetworksModule()
{
    return static_cast<IMonitorModule *>(new NetworksModule());
}

IMonitorModule* FactoryMethod::createVirtualMemModule()
{
    return static_cast<IMonitorModule *>(new VirtualMemModule());
}

IMonitorModule* FactoryMethod::createDisksModule()
{
    return static_cast<IMonitorModule *>(new DisksModule());
}


IMonitorModule* FactoryMethod::createModule(const std::string &command)
{
    for(unsigned int i = 0; i < SIZE_STACK_STRUCT(arrayToCreateModules, t_toCreateModules); i++)
    {
        if (command == arrayToCreateModules[i].module)
            return (this->*arrayToCreateModules[i].prt)();
    }
    return (nullptr);
}
