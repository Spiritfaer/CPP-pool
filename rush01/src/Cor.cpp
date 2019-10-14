//
// Created by Denis LEWANDOWSKI on 2019-10-12.
//

#include "Cor.hpp"

namespace
{

    std::string availableCommands[AVALIABLE_COMMANDS_NUMBER] = {"-os", "-dt", "-cpu", "-ram", "-net", "-vm", "-hd"};


    bool    checkCurrentCommand(const std::string &currentCommand)
    {
        for (int i = 0; i < AVALIABLE_COMMANDS_NUMBER; i++)
        {
            if (currentCommand == availableCommands[i])
                return true;
        }
        return false;
    }
}

void Cor::createVectorOfModules(int argc, char **argv)
{
    int i = 1;
    FactoryMethod factoryMethod;

    if (argc == 1)
    {
        i = 0;
        while (i < AVALIABLE_COMMANDS_NUMBER)
        {
            vectorOfModules.push_back(factoryMethod.createModule(availableCommands[i]));
            i++;
        }
    }
    else
    {
        while (i < argc)
        {
            if (checkCurrentCommand(argv[i]))
                vectorOfModules.push_back(factoryMethod.createModule(argv[i]));
            else {
                throw std::logic_error("usage:");
            }
            i++;
        }
    }
}

const std::vector<IMonitorModule *>& Cor::getModules() const
{
    return vectorOfModules;
}

Cor::Cor(int argc, char *argv[])
{
    createVectorOfModules(argc, argv);
}
