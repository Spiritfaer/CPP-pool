
#ifndef RUSH_01_FACTORYMETHOD_HPP
#define RUSH_01_FACTORYMETHOD_HPP

#include "IMonitorModule.hpp"
#include "OSHostModule.hpp"
#include "TimeDateModule.hpp"
#include "VirtualMemModule.hpp"
#include "DisksModule.hpp"
#include "CpuUsageModule.hpp"
#include "PhysMemModule.hpp"
#include "NetworksModule.hpp"
#include <iostream>

#define SIZE_STACK_STRUCT(array, type_array) (sizeof(array) / sizeof(type_array))

typedef struct s_toCreateModules t_toCreateModules;

class FactoryMethod {
public:
    FactoryMethod();
    ~FactoryMethod();

    IMonitorModule *createModule(const std::string &command); //возвращает указатель на объект модуля через интерфейс

private:
    FactoryMethod(FactoryMethod const &);
    FactoryMethod &operator=(FactoryMethod const &);


    IMonitorModule *createOsHostModule(); // создание OSHostModule
    IMonitorModule *createTimeDataModule(); // создание OSHostModule
    IMonitorModule *createCpuUsageModule(); // создание OSHostModule
    IMonitorModule *createPhysMemModule(); // создание OSHostModule
    IMonitorModule *createNetworksModule(); // создание OSHostModule
    IMonitorModule *createVirtualMemModule(); // создание OSHostModule
    IMonitorModule *createDisksModule(); // создание OSHostModule



    static t_toCreateModules arrayToCreateModules[];//структура: название модуля + указатель на функцию которая создает указатель на объект
};

#endif
