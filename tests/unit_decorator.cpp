// This tests the entire decorator
#include <gtest/gtest.h>
#include "../src/Buildings/ComMall.h"
#include "../src/Buildings/BuildDecorRepair.h"

TEST(BuildingDecoratorTest, DisplayBuildingInfoWithRepair) {
    ComMall* mall = new ComMall();
    BuildDecorRepair* repairedMall = new BuildDecorRepair(mall);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    repairedMall->displayBuildingInfo();
    std::cout.rdbuf(old);

    std::string output = buffer.str();
    EXPECT_TRUE(output.find("Mall with") != std::string::npos);  // Checks that original info is displayed
    EXPECT_TRUE(output.find("This building has been repaired.") != std::string::npos); // Checks repair message

    delete repairedMall;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
