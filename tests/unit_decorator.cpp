// This tests the entire decorator
#include <gtest/gtest.h>
#include "../src/Buildings/ComMall.h"
#include "../src/Buildings/BuildDecorRepair.h"
#include "../src/Buildings/BuildDecorUpgrade.h"
#include "../src/Buildings/BuildDecorEconomic.h"

// Test case to check if the BuildDecorRepair decorator correctly wraps the ComMall
TEST(BuildingDecoratorTest, DisplayBuildingInfoWithRepair) {
    ComMall* mall = new ComMall();
    BuildDecorRepair* repairedMall = new BuildDecorRepair(mall);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    repairedMall->displayBuildingInfo();

    std::cout.rdbuf(old);

    std::string output = buffer.str();
    EXPECT_TRUE(output.find("Mall with") != std::string::npos);
    EXPECT_TRUE(output.find("This building has been repaired.") != std::string::npos);

    delete repairedMall;
}

// Test case to check if the BuildDecorUpgrade decorator correctly wraps the ComMall
TEST(BuildingDecoratorTest, DisplayBuildingInfoWithUpgrade) {
    ComMall* mall = new ComMall();
    BuildDecorUpgrade* upgradedMall = new BuildDecorUpgrade(mall);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    upgradedMall->displayBuildingInfo();

    std::cout.rdbuf(old);

    std::string output = buffer.str();
    EXPECT_TRUE(output.find("Mall with") != std::string::npos);
    EXPECT_TRUE(output.find("This building has been upgraded with decorative elements.") != std::string::npos);

    delete upgradedMall;
}

// Test case to check if the BuildDecorEconomic decorator correctly wraps the ComMall
TEST(BuildingDecoratorTest, DisplayBuildingInfoWithEconomicUpgrade) {
    ComMall* mall = new ComMall();
    BuildDecorEconomic* economicMall = new BuildDecorEconomic(mall);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    economicMall->displayBuildingInfo();

    std::cout.rdbuf(old);

    std::string output = buffer.str();
    EXPECT_TRUE(output.find("Mall with") != std::string::npos);
    EXPECT_TRUE(output.find("This building has been upgraded with economic elements.") != std::string::npos);

    delete economicMall;
}

// Test case to check if multiple decorators work together
TEST(BuildingDecoratorTest, DisplayBuildingInfoWithMultipleDecorators) {
    ComMall* mall = new ComMall();
    BuildDecorRepair* repairedMall = new BuildDecorRepair(mall);
    BuildDecorUpgrade* upgradedMall = new BuildDecorUpgrade(repairedMall);
    BuildDecorEconomic* economicMall = new BuildDecorEconomic(upgradedMall);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    economicMall->displayBuildingInfo();

    std::cout.rdbuf(old);

    std::string output = buffer.str();
    EXPECT_TRUE(output.find("Mall with") != std::string::npos);
    EXPECT_TRUE(output.find("This building has been repaired.") != std::string::npos);
    EXPECT_TRUE(output.find("This building has been upgraded with decorative elements.") != std::string::npos);
    EXPECT_TRUE(output.find("This building has been upgraded with economic elements.") != std::string::npos);

    delete economicMall;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
