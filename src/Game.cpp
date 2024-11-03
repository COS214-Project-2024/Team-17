#include "Game.h"
#include "resources.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>

static constexpr int GAME_SPEED = 17;                   // millisecond timeout
static constexpr int TRANSPORT_UPDATE_INTERVAL = 1;     // Every 10 minutes
static constexpr int CONSTRUCTION_UPDATE_INTERVAL = 60; // Every 6 hours
static constexpr int JOB_UPDATE_INTERVAL = 6;           // Every 1 hour
static constexpr int CITY_GROWTH_INTERVAL = 240;        // Every 1 day
static constexpr int CITY_TAX_INTERVAL = 240;           // Every 1 day
int time_of_day = 0;

Game::Game()
{
  Resources::removePopulation(Resources::getPopulation());
  this->mediator = CityCentralMediator::getInstance();
  delete mediator;
  this->mediator = CityCentralMediator::getInstance();
  CityStructure* city = new CityStructure("Pretoria");
  city->addBlock(new CityBlock());
  this->gov.addCity(*city);
  mediator->registerBuilding(new ResFlat());
  mediator->registerBuilding(new ResHouse());
}

void Game::updateTransport()
{
  if(mediator)
  {
    mediator->updateBuses();
  }
}

void Game::updateJobs()
{
  if(mediator)
  {
    if(time_of_day == 8)
    {
      mediator->citizensStartWork();
    }
    if(time_of_day == 17)
    {
      mediator->citizensEndWork();
    }
  }
}

void Game::updateCityGrowth()
{
  if(mediator)
  {
    mediator->citizensDoSomething();
    mediator->handlePopulationGrowth();
    mediator->updateCitizenSatisfaction();
  }
}

std::string toLowerCase(const std::string& str) 
{
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void Game::updateCityTax()
{
   std::string input;
  bool paused = false;
   while (true) 
   {
        if (!paused) 
        {
            std::cout << "What action do you want to do? (Laws, Taxes, Pause, Skip): ";
            std::cin >> input;
            input = toLowerCase(input);
        }
        
        if (input == "skip") 
        {
            break;
        }
        else if (input == "pause") 
        {
            std::cout << "System paused. Type 'resume' to continue: ";
            paused = true;
            while (paused) {
                std::cin >> input;
                if (toLowerCase(input) == "resume") 
                {
                    paused = false;
                } else {
                    std::cout << "Invalid input. Type 'resume' to continue: ";
                }
            }
            continue;
        }
        else if (input == "laws") 
        {
            while (true) {
                std::cout << "What do you want to do in Laws? (On, Off, List, Back): ";
                std::cin >> input;
                input = toLowerCase(input);

                if (input == "on") 
                {
                    std::cout << "Give the name of the law you want to enable (bus, happiness, money, notax, services): ";
                    std::cin >> input;
                    input = toLowerCase(input);
                                        
                    if (input == "bus") 
                    {
                      Policy::setBusLaw(true);
                    } 
                    else if (input == "happiness") 
                    {
                      Policy::setHappinessLaw(true);
                    } 
                    else if (input == "money") 
                    {
                      Policy::setMoneyLaw(true);
                    } 
                    else if (input == "notax") 
                    {
                      Policy::setNoTaxLaw(true);
                    } 
                    else if (input == "services") 
                    {
                      Policy::setServicesLaw(true);
                    } 
                    else 
                    {
                      std::cout << "Unrecognized law name." << std::endl;
                    }
                    std::cout << "Enabled law: " << input << "\n";
                } 
                else if (input == "off") 
                {
                }
                else if (input == "list") 
                {
                    std::cout << "Policy Status:" << std::endl;
                    std::cout << "- Bus Law: " << (Policy::getBusLaw() ? "Enabled" : "Disabled") << std::endl;
                    std::cout << "- Happiness Law: " << (Policy::getHappinessLaw() ? "Enabled" : "Disabled") << std::endl;
                    std::cout << "- Money Law: " << (Policy::getMoneyLaw() ? "Enabled" : "Disabled") << std::endl;
                    std::cout << "- No Tax Law: " << (Policy::getNoTaxLaw() ? "Enabled" : "Disabled") << std::endl;
                    std::cout << "- Services Law: " << (Policy::getServicesLaw() ? "Enabled" : "Disabled") << std::endl;
                }
                else if (input == "back") 
                {
                    break;
                }
                else 
                {
                    std::cout << "Invalid action. Please try again.\n";
                }
            }
        }
        else if (input == "taxes") 
        {
            while (true) 
            {
                std::cout << "What do you want to do in Taxes? (Execute, Add, Remove, List, Back): ";
                std::cin >> input;
                input = toLowerCase(input);

                if (input == "execute") 
                {
                    std::cout << "Give the name of the policy you want to execute: ";
                    std::cin >> input;
                    if (this->taxManager.executeCommand(input))
                    std::cout << "Executed policy: " << input << "\n";
                }
                else if (input == "add") 
                {
                    std::cout << "What type of policy do you want to add? (Allocate, Collect, SetRate): ";
                    std::cin >> input;
                    input = toLowerCase(input);

                    if (input == "allocate") 
                    {
                        std::string name, department;
                        double amount;
                        std::cout << "Enter name for the tax policy: ";
                        std::cin >> name;
                        std::cout << "Enter tax amount: ";
                        std::cin >> amount;
                        std::cout << "Enter department for allocation: ";
                        std::cin >> department;
                        TaxCommand* command = new AllocateTaxCommand(&this->gov, amount, department);
                        this->taxManager.addCommand(name, command);
                        std::cout << "Added allocation command: " << name << "\n";
                    }
                    else if (input == "collect") 
                    {
                        std::string name;
                        std::cout << "Enter name for the collection command: ";
                        std::cin >> name;
                        TaxCommand* command = new CollectTaxCommand(&this->gov);
                        this->taxManager.addCommand(name, command);
                        std::cout << "Added collection command: " << name << "\n";
                    }
                    else if (input == "setrate") 
                    {
                        std::string name, category;
                        double rate;
                        std::cout << "Enter name for the rate command: ";
                        std::cin >> name;
                        std::cout << "Enter tax rate: ";
                        std::cin >> rate;
                        std::cout << "Enter category for the rate: ";
                        std::cin >> category;
                        TaxCommand* command = new SetTaxRateCommand(&this->gov, rate, category);
                        this->taxManager.addCommand(name, command);
                        std::cout << "Added rate command: " << name << "\n";
                    }
                }
                else if (input == "list") 
                {
                    this->taxManager.listCommands();
                }
                else if (input == "back") 
                {
                    break;
                }
                else 
                {
                    std::cout << "Invalid action. Please try again.\n";
                }
            }
        }
        else 
        {
            std::cout << "Invalid main action. Please try again.\n";
        }
    }
}

void Game::start()
{
    running = true;
    counter = 0;
    while (running)
    {
        if (counter % TRANSPORT_UPDATE_INTERVAL == 0)
        { 
          time_of_day++;
          if(time_of_day > 24)
          {
            time_of_day = 0;
          }
          updateTransport();
        }
        if (counter % JOB_UPDATE_INTERVAL == 0)
        {
            updateJobs();
        }
        if (counter % CITY_GROWTH_INTERVAL == 0)
        {
            updateCityGrowth();
        }
        if (counter % CITY_TAX_INTERVAL == 0)
        {
            updateCityTax();
        }
        counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(GAME_SPEED));
    }
}