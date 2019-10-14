//
// Created by Denis LEWANDOWSKI on 2019-10-12.
//

#ifndef RUSH_01_COR_HPP
#define RUSH_01_COR_HPP

#include "IMonitorModule.hpp"
#include <iostream>
#include "FactoryMethod.hpp"
#include <vector>

#define AVALIABLE_COMMANDS_NUMBER 7

class Cor {
public:
    Cor(int argc, char *argv[]);

    const std::vector<IMonitorModule *> &getModules() const;

private:
    void    createVectorOfModules(int argc, char *argv[]);

    std::vector<IMonitorModule *> vectorOfModules;
};


#endif //RUSH_01_COR_HPP
