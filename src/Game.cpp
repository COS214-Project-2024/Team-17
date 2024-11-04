#include "Game.h"
#include "resources.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
#include "./Transport/TransportInclude.h"
#include "./Citizens/CitizensIncludes.h"

static constexpr int GAME_SPEED = 20;               // millisecond timeout
static constexpr int TURN_INTERVAL = 5;             // 5 minutes per turn
static constexpr int TRANSPORT_UPDATE_INTERVAL = 1; // Every turn (5 minutes)
static constexpr int CITIZEN_UPDATE_INTERVAL = 2;   // Every 10 minutes (2 turns)
static constexpr int CITIZEN_GROWTH_TIME = 7;       // 8 AM
static constexpr int JOB_UPDATE_TIME = 8;           // 8 AM
static constexpr int WORK_START_TIME = 9;           // 9 AM
static constexpr int WORK_END_TIME = 17;            // 5 PM
static constexpr int TAX_COLLECTION_TIME = 18;      // 6 PM
int time_of_day = 0;

Game::Game()
{
  Resources::removePopulation(Resources::getPopulation());
  Resources::addMoney(10000);
  Resources::addWood(100);
  Resources::addConcrete(100);
  Resources::addSteel(100);
  this->mediator = CityCentralMediator::getInstance();
  delete mediator;
  this->mediator = CityCentralMediator::getInstance();
  CityStructure *city = new CityStructure("Pretoria");//Need to deallocate
  city->addBlock(new CityBlock());
  this->gov.addCity(*city);
  initBuildingOptions();
  initRoadGrid();
}

Game::~Game()
{
  if(mediator){
    delete mediator;
  }
}

std::string toLowerCase(const std::string &str)
{
  std::string lowerStr = str;
  std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
  return lowerStr;
}

void Game::updateTransport()
{
  std::cout << BLACK << "Simulating traffic..." << RESET << std::endl;
  if (mediator)
  {
    mediator->updateBuses();
  }
}

void Game::updateJobs()
{
  cout << "Updating jobs for " << Resources::getPopulation() << " citzens:" << endl;
  if (mediator)
  {
    mediator->updateJobs();
  }
  cout << GREEN << "Jobs updated!" << RESET << endl
       << endl;
}

void Game::citizensGoToWork()
{
  cout << GREEN << "Notified " << Resources::getPopulation() << " citzens that it's time for work!" << RESET << endl
       << endl;
  if (mediator)
  {
    mediator->citizensStartWork();
  }
}

void Game::outputResources()
{
  cout << BOLD << BLUE << "Resources updated:" << RESET << endl;
  cout << YELLOW << "Wood: " << RESET << Resources::getWood() << "(" << Resources::getWoodPerTick() << ")" << endl;
  cout << YELLOW << "Steel: " << RESET << Resources::getSteel() << "(" << Resources::getSteelPerTick() << ")" << endl;
  cout << YELLOW << "Concrete: " << RESET << Resources::getConcrete() << "(" << Resources::getConcretePerTick() << ")" << endl;
  cout << YELLOW << "Money: " << RESET << Resources::getMoney() << "(" << Resources::getIncome() << ")" << endl
       << endl;
  cout << YELLOW << "Overall Happiness: " << RESET << Resources::getHappiness() << endl;
  cout << YELLOW << "Electricity generated: " << RESET << Resources::getElectricityGenerated() << endl;
  cout << YELLOW << "Electricity consumed: " << RESET << Resources::getElectricityUsage() << endl;
  cout << YELLOW << "Water generated: " << RESET << Resources::getWaterGenerated() << endl;
  cout << YELLOW << "Water consumed: " << RESET << Resources::getWaterUsage() << endl;
}

void Game::updateResources()
{
  Resources::addConcrete(Resources::getConcretePerTick());
  Resources::addSteel(Resources::getSteelPerTick());
  Resources::addWood(Resources::getWoodPerTick());
  Resources::addMoney(Resources::getIncome());

  outputResources();
}

void Game::citizensGoHome()
{
  cout << GREEN << "Notified " << Resources::getPopulation() << " citzens that it's time to go home!" << RESET << endl
       << endl;
  if (mediator)
  {
    mediator->citizensEndWork();
  }
}

void Game::updateCityGrowth()
{
  if (mediator)
  {
    mediator->handlePopulationGrowth();
  }
}

void Game::handleTransport()
{
  // ask the user if they want to create or remove a bus
  while (true)
  {
    std::string input;
    std::cout << "What do you want to do in Transport? (Create, Remove, List, Back): ";
    std::cin >> input;
    input = toLowerCase(input);
    if (input == "create")
    {
      RoadComponent *comp = mediator->getClosestRoad(0, 0);
      // prompt user for bus capacity and validate input using isValidNumber()
      int capacity;
      std::cout << "Enter the bus capacity: ";
      std::cin >> input;
      if (!isValidNumber(input, capacity) || capacity < 0)
      {
        std::cout << RED << "Invalid capacity value." << RED << std::endl;
        continue;
      }

      Bus *bus = new Bus(comp, capacity);
    }
    else if (input == "list")
    {
      std::cout << "There are " << RED << mediator->getBusCount() << RESET << " inactive buses in the city." << std::endl;
    }
    else if (input == "remove")
    {
      mediator->removeBus();
    }
    else if (input == "back")
    {
      return;
    }
    else
    {
      std::cout << "Invalid action. Please try again.\n";
    }
  }
}

void Game::citizensDoSomething()
{
  std::cout << BLACK << "Simulating citizen activity..." << RESET << std::endl;
  if (mediator)
  {
    mediator->citizensDoSomething();
  }
}

void Game::updateCityTax()
{
  if (mediator)
  {
    cout << "Collecting taxes..." << endl
         << endl;
    // mediator->collectTaxes();
  }
}

int Game::promptUserAction()
{
  std::string input;
  bool paused = false;
  while (true)
  {
    if (!paused)
    {
      std::cout << "What action do you want to do? (Build, Laws, Taxes, Transport, Resources, Pause, Skip, Quit): ";
      std::cin >> input;
      input = toLowerCase(input);
    }

    if (input == "skip")
    {
      return 1;
    }
    else if (input == "quit")
    {
      exit(0);
    }
    else if (input == "pause")
    {
      std::cout << "System paused. Type 'resume' to continue: ";
      paused = true;
      while (paused)
      {
        std::cin >> input;
        if (toLowerCase(input) == "resume")
        {
          paused = false;
        }
        else
        {
          std::cout << "Invalid input. Type 'resume' to continue: ";
        }
      }
      continue;
    }
    else if (input == "laws")
    {
      while (true)
      {
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
            TaxCommand *command = new AllocateTaxCommand(&this->gov, amount, department);
            this->taxManager.addCommand(name, command);
            std::cout << "Added allocation command: " << name << "\n";
          }
          else if (input == "collect")
          {
            std::string name;
            std::cout << "Enter name for the collection command: ";
            std::cin >> name;
            TaxCommand *command = new CollectTaxCommand(&this->gov);
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
            TaxCommand *command = new SetTaxRateCommand(&this->gov, rate, category);
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
    else if (input == "build")
    {
      createBuilding();
    }
    else if (input == "transport")
    {
      handleTransport();
    }
    else if (input == "resources")
    {
      outputResources();
    }
    else
    {
      std::cout << "Invalid main action. Please try again.\n";
    }
  }
  return 0;
}

void Game::start()
{
  running = true;
  counter = 0;
  bool skip = false;
  // clear screen
  std::cout << "\033[2J\033[1;1H";
  cout << YELLOW << "\t┏┓•     ┳┓  •┓ ┓      " << endl
       << "\t┃ ┓╋┓┏  ┣┫┓┏┓┃┏┫┏┓┏┓  " << endl
       << "\t┗┛┗┗┗┫  ┻┛┗┻┗┗┗┻┗ ┛   " << endl
       << "\t     ┛                 " << RESET << endl
       << endl;
  while (running)
  {
    // clear output
    if (!skip)
    {
      skip = promptUserAction() == 1;
    }

    // Update transport every turn (5 minutes)
    if (counter % TRANSPORT_UPDATE_INTERVAL == 0)
    {
      updateTransport();
    }

    // Update citizens every 10 minutes (2 turns)
    if (counter % CITIZEN_UPDATE_INTERVAL == 0)
    {
      citizensDoSomething();
    }

    // Specific time-based events
    if (time_of_day == CITIZEN_GROWTH_TIME)
    {
      std::cout << "======= City Growth =======" << std::endl;
      updateCityGrowth();
      skip = false;
    }
    if (time_of_day == JOB_UPDATE_TIME)
    {
      std::cout << "======= Jobs Updating =======" << std::endl;
      updateJobs();
      skip = false;
    }
    if (time_of_day == WORK_START_TIME)
    {
      std::cout << "======= Citizens Going to Work =======" << std::endl;
      citizensGoToWork();
      skip = false;
    }
    if (time_of_day == WORK_END_TIME)
    {
      std::cout << "======= Citizens Going Home =======" << std::endl;
      citizensGoHome();
      updateResources();
      skip = false;
    }
    if (time_of_day == TAX_COLLECTION_TIME)
    {
      std::cout << "======= Tax Collected =======" << std::endl;
      updateCityTax();
      skip = false;
    }

    // Increment time of day and counter
    time_of_day++;
    if (time_of_day >= 24)
    {
      time_of_day = 0;
    }
    counter++;

    std::this_thread::sleep_for(std::chrono::milliseconds(GAME_SPEED));
  }
}

void Game::initBuildingOptions()
{
  buildingOptions = {
      {"Residential", {"House", "Flat", "Townhouse", "Estate"}},
      {"Commercial", {"Mall", "Shop", "Office"}},
      {"Industrial", {"Warehouse", "Factory", "Plant"}},
      {"Landmarks", {"Park", "Monument", "Community Center"}},
      {"Services", {"Education", "Security", "Entertainment", "Hospital"}}};
}

void Game::initRoadGrid()
{
  RoadComponent *horizRoads[20][19];
  RoadComponent *vertRoads[19][20];

  // Create horizontal roads
  for (int y = 0; y < 20; y++)
  {
    for (int x = 0; x < 19; x++)
    {
      horizRoads[y][x] = new RoadsComposite(
          x * 100, y * 100,
          (x + 1) * 100, y * 100,
          "residential");
      mediator->registerRoad(horizRoads[y][x]);
    }
  }

  // Create vertical roads
  for (int y = 0; y < 19; y++)
  {
    for (int x = 0; x < 20; x++)
    {
      vertRoads[y][x] = new RoadsComposite(
          x * 100, y * 100,
          x * 100, (y + 1) * 100,
          "residential");
      mediator->registerRoad(vertRoads[y][x]);
    }
  }

  // Connect horizontal roads
  for (int y = 0; y < 20; y++)
  {
    for (int x = 1; x < 19; x++)
    {
      float dist = 100; // Distance between road segments
      horizRoads[y][x]->addConnection(horizRoads[y][x - 1], dist);
      horizRoads[y][x - 1]->addConnection(horizRoads[y][x], dist);
    }
  }

  // Connect vertical roads
  for (int y = 1; y < 19; y++)
  {
    for (int x = 0; x < 20; x++)
    {
      float dist = 100;
      vertRoads[y][x]->addConnection(vertRoads[y - 1][x], dist);
      vertRoads[y - 1][x]->addConnection(vertRoads[y][x], dist);
    }
  }

  // Connect intersections
  for (int y = 0; y < 19; y++)
  {
    for (int x = 0; x < 19; x++)
    {
      float dist = 100;
      vertRoads[y][x]->addConnection(horizRoads[y][x], dist);
      horizRoads[y][x]->addConnection(vertRoads[y][x], dist);

      vertRoads[y][x + 1]->addConnection(horizRoads[y][x], dist);
      horizRoads[y][x]->addConnection(vertRoads[y][x + 1], dist);
    }
  }
}

void Game::createBuilding()
{
  if (numBuildings >= MAX_BUILDINGS)
  {
    cout << RED << "Maximum number of buildings reached!" << RESET << endl;
    return;
  }

  string input;
  int option, option2;
  string buildingType;
  int capacity;

  cout << "What Building Type do you want to build?" << endl;
  cout << "Choose an option: " << endl;
  for (int i = 0; i < buildingOptions.size(); ++i)
  {
    cout << i + 1 << ". " << buildingOptions[i].type << ":";
    for (const auto &subtype : buildingOptions[i].subtypes)
    {
      cout << " " << subtype << ",";
    }
    cout << endl;
  }

  cout << "Enter your choice: ";
  getline(cin >> ws, input);
  if (!isValidNumber(input, option) || option < 1 || option > buildingOptions.size())
  {
    cout << RED << "Invalid building type selection." << RESET << endl;
    return;
  }

  const auto &selectedOption = buildingOptions[option - 1];
  cout << "What kind of " << selectedOption.type << " Building?" << endl;
  cout << "Choose an option: " << endl;
  for (int i = 0; i < selectedOption.subtypes.size(); ++i)
  {
    cout << "\t" << i + 1 << ". " << selectedOption.subtypes[i] << endl;
  }

  cout << "Enter your choice: ";
  getline(cin >> ws, input);
  if (!isValidNumber(input, option2) || option2 < 1 || option2 > selectedOption.subtypes.size())
  {
    cout << RED << "Invalid building subtype selection." << RESET << endl;
    return;
  }

  buildingType = selectedOption.subtypes[option2 - 1];

  // Find next available intersection
  auto [x, y] = findNextFreeIntersection();
  if (x == -1)
  {
    cout << RED << "No free intersections available!" << RESET << endl;
    return;
  }

  Building *building = nullptr;
  if (selectedOption.type == "Residential")
  {
    cout << "Enter the capacity: ";
    getline(cin >> ws, input);
    if (!isValidNumber(input, capacity) || capacity < 0)
    {
      cout << RED << "Invalid capacity value." << RESET << endl;
      return;
    }
    FactoryBuilding *factory = new FactResidential();
    if (BuildingRequirements::checkResidentialRequirements(buildingType))
    {
      Residential *res = factory->createResBuilding(buildingType);

      res->setCapacity(capacity);
      building = res;
    }
    else
    {
      cout << RED << "Not enough resources!" << RESET << endl;
    }
    delete factory;
  }
  else if (selectedOption.type == "Commercial")
  {
    FactoryBuilding *factory = new FactCommercial();
    if (BuildingRequirements::checkCommercialRequirements(buildingType))
    {
      Commercial *com = factory->createComBuilding(buildingType);
      com->setJobCapacity(100); // Default value
      building = com;
    }
    else
    {
      cout << RED << "Not enough resources!" << RESET << endl;
    }
    delete factory;
  }
  else if (selectedOption.type == "Industrial")
  {
    FactoryBuilding *factory = new FactIndustrial();
    if (BuildingRequirements::checkIndustrialRequirements(buildingType))
    {
      Industrial *ind = factory->createIndBuilding(buildingType);
      ind->setProductionCapacity(100); // Default value
      building = ind;
    }
    else
    {
      cout << RED << "Not enough resources!" << RESET << endl;
    }
    delete factory;
  }
  else if (selectedOption.type == "Landmarks")
  {
    FactoryBuilding *factory = new FactLandmarks();
    Landmark *land = factory->createLandmark(buildingType);
    building = land;
    delete factory;
  }
  else if (selectedOption.type == "Services")
  {
    FactoryBuilding *factory = new FactService();
    if (BuildingRequirements::checkServiceRequirements(buildingType))
    {
      Services *serv = factory->createServiceBuilding(buildingType);
      building = serv;
    }
    delete factory;
  }

  if (building)
  {
    building->setXCoordinate(x);
    building->setYCoordinate(y);
    mediator->registerBuilding(building);
    numBuildings++;
    cout << GREEN << "Created " << buildingType << " at intersection ("
         << x / 100 << "," << y / 100 << ")" << RESET << endl;
  }
}

std::pair<int, int> Game::findNextFreeIntersection()
{
  for (int y = 0; y < 20; y++)
  {
    for (int x = 0; x < 19; x++)
    {
      if (!intersectionOccupied[y][x])
      {
        intersectionOccupied[y][x] = true;
        return {x * 100, y * 100}; // Return grid coordinates
      }
    }
  }
  return {-1, -1}; // No free spots
}

bool Game::isValidNumber(const string &input, int &number)
{
  stringstream ss(input);
  return (ss >> number) && ss.eof();
}