#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include "TaxCommand.h"
#include "CollectTaxCommand.h"
#include <map>
#include <string>
#include <memory>

class TaxManager
{
private:
    std::map<std::string, TaxCommand*> commands;
public:
    void addCommand(const std::string& name, TaxCommand* cmd);
    void removeCommand(const std::string& name);
    void listCommands() const;
    bool executeCommand(const std::string& name) const;
    bool executeCollect() const;
};

#endif
