#include "TaxManager.h"
#include <iostream>

void TaxManager::addCommand(const std::string& name, TaxCommand* cmd) {
    commands[name] = cmd;
}

void TaxManager::removeCommand(const std::string& name) {
    auto it = commands.find(name);
    if (it != commands.end()) {
        commands.erase(it);
    } else {
        std::cout << "Command not found: " << name << std::endl;
    }
}

void TaxManager::listCommands() const {
    if(commands.size() < 1)
    {
      std::cout << "No commands added\n";
      return;
    }
    for (const auto& [name, cmd] : commands) {
        std::cout << "- " << name << std::endl;
    }
}
bool TaxManager::executeCommand(const std::string& name) const {
    auto it = commands.find(name);
    if (it != commands.end()) {
        it->second->execute();
        return true;
    } else {
        std::cout << "Command not found: " << name << std::endl;
        return false;
    }
}
