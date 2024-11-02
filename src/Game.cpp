#include "Game.h"

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

Game::Game()
{
  CityStructure* city = new CityStructure("Pretoria");
  this->gov.addCity(*city);
}

void Game::updateTransport()
{
    std::cout << "Transport updated" << std::endl;
}

void Game::updateConstruction()
{
    std::cout << "Construction updated" << std::endl;
}

void Game::updateJobs()
{
    std::cout << "Jobs updated" << std::endl;
}

void Game::updateCityGrowth()
{
    this->gov.enactPolicies();
    std::cout << "Policies/laws enacted\n";
}

std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void Game::updateCityTax()
{
  std::string input;
  this->gov.collectTaxes();
  while(true)
  {
    std::cout << "What action do you want to do? (Laws,Taxes,Nothing): ";
    std::cin >> input;

    input = toLowerCase(input);
    if(input == "laws")
    {
      while(true)
      {
        std::cout << "What do you want to do? (Add,Remove,List): ";
        std::cin >> input;
        input = toLowerCase(input);
        if(input == "add")
        {
          std::cout << "Give the name of the law you want to add: ";
          std::cin >> input;
          Policy* law = new Law(&this->gov);
          this->gov.addPolicy(*law,input);
          break;
        }
        else if(input == "remove")
        {
          std::cout << "Give the name of the law you want to remove: ";
          std::cin >> input;
          this->gov.removePolicy(input);
          break;
        }
        else if(input == "list")
        {
          this->gov.listPolicies();
        }
      }
    }
    else if(input == "taxes") 
    {
      while(true)
      {
        std::cout << "What do you want to do? (Execute,Add,Remove,List): ";
        std::cin >> input;

        input = toLowerCase(input);
        if(input == "execute")
        {
          std::cout << "Give the name of the command you want to execute: ";
          std::cin >> input;
          if(this->taxManager.executeCommand(input))
          break;
        }
        else if(input == "add")
        {
          std::cout << "What type of policy do you want to add? (Allocate,Collect,SetRate): ";
          std::cin >> input;
          input = toLowerCase(input);

          if(input == "allocate")
          {
            std::cout << "What name do you want to give to your new tax policy?: ";
            std::string name;
            std::cin >> name;

            std::cout << "How much tax do you want to allocate?: ";
            double amount;
            std::cin >> amount;

            std::cout << "What department should this tax go to?: ";
            std::string department;
            std::cin >> department;
            TaxCommand* command = new AllocateTaxCommand(&this->gov,amount,department);
            this->taxManager.addCommand(name,command);
          }
          else if(input == "collect")
          {
            std::cout << "What name do you want to give to your new command?: ";
            std::string name;
            std::cin >> name;

            TaxCommand* command = new CollectTaxCommand(&this->gov);
            this->taxManager.addCommand(name,command);
          }
          else if(input == "setrate")
          {
            std::cout << "What name do you want to give to your new command?: ";
            std::string name;
            std::cin >> name;

            std::cout << "How much should the rate be?: ";
            double rate;
            std::cin >> rate;

            std::cout << "What category should the rate be attributed to?: ";
            std::string category;
            std::cin >> category;

            TaxCommand* command = new SetTaxRateCommand(&this->gov,rate,category);
            this->taxManager.addCommand(name,command);
          }
          break;
        }
        else if(input == "list")
        {
          this->taxManager.listCommands();
        }
      }
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
            updateTransport();
        }
        if (counter % CONSTRUCTION_UPDATE_INTERVAL == 0)
        {
            updateConstruction();
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