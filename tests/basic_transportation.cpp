#include "../src/Transport/TransportInclude.h"

void testConstructors()
{
    Highways *highway = new Highways(0, 0, 10, 10);
    MainRoads *mainRoad = new MainRoads(0, 0, 10, 10);
    ResidentialStreets *residentialStreet = new ResidentialStreets(0, 0, 10, 10);
    RoadsComposite *roadsComposite = new RoadsComposite(0, 0, 10, 10, "highway");

    highway->displayInfo();
    mainRoad->displayInfo();
    residentialStreet->displayInfo();
    roadsComposite->displayInfo();
}

int main()
{
    testConstructors();
    return 0;
}