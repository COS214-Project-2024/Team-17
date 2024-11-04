// This file is used to test the Factory classes

#include <gtest/gtest.h>
#include "../src/Buildings/FactResidential.h"
#include "../src/Buildings/ResHouse.h"
#include "../src/Buildings/ResTownhouse.h"
#include "../src/Buildings/ResFlat.h"
#include "../src/Buildings/ResEstate.h"

#include "../src/Buildings/FactCommercial.h"
#include "../src/Buildings/ComMall.h"
#include "../src/Buildings/ComShop.h"
#include "../src/Buildings/ComOffice.h"

#include "../src/Buildings/FactIndustrial.h"
#include "../src/Buildings/IndFactory.h"
#include "../src/Buildings/IndWarehouse.h"
#include "../src/Buildings/IndPlant.h"

#include "../src/Buildings/FactLandmarks.h"
#include "../src/Buildings/LandPark.h"
#include "../src/Buildings/LandMonument.h"
#include "../src/Buildings/LandCCenter.h"

#include "../src/Buildings/FactService.h"
#include "../src/Buildings/ServEducation.h"
#include "../src/Buildings/ServSecurity.h"
#include "../src/Buildings/ServEntertainment.h"

class FactTest : public ::testing::Test {
protected:
    FactResidential resFactory;
    FactCommercial comFactory;
    FactIndustrial indFactory;
    FactLandmarks landmarkFactory;
    FactService serviceFactory;
};

// Test that the Residential factory is created
TEST_F(FactTest, ResidentialFactoryCreation) {
    ASSERT_NO_THROW(FactResidential());
}

// Test creating Residential buildings
TEST_F(FactTest, CreateHouse) {
    Residential* building = resFactory.createResBuilding("House");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<ResHouse*>(building) != nullptr);
    delete building;
}

TEST_F(FactTest, CreateTownhouse) {
    Residential* building = resFactory.createResBuilding("Townhouse");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<ResTownhouse*>(building) != nullptr);
    delete building;
}

TEST_F(FactTest, CreateFlat) {
    Residential* building = resFactory.createResBuilding("Flat");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<ResFlat*>(building) != nullptr);
    delete building;
}

TEST_F(FactTest, CreateEstate) {
    Residential* building = resFactory.createResBuilding("Estate");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<ResEstate*>(building) != nullptr);
    delete building;
}

// Test that unsupported Residential type returns nullptr
TEST_F(FactTest, CreateUnknownResidentialType) {
    Residential* building = resFactory.createResBuilding("Castle");
    EXPECT_EQ(building, nullptr);
}

// Test that other building types return nullptr in the Residential factory
TEST_F(FactTest, ResidentialFactoryUnsupportedTypes) {
    EXPECT_EQ(resFactory.createComBuilding("Mall"), nullptr);
    EXPECT_EQ(resFactory.createComBuilding("Shop"), nullptr);
    EXPECT_EQ(resFactory.createComBuilding("Office"), nullptr);
    EXPECT_EQ(resFactory.createIndBuilding("Factory"), nullptr);
    EXPECT_EQ(resFactory.createIndBuilding("Warehouse"), nullptr);
    EXPECT_EQ(resFactory.createIndBuilding("Plant"), nullptr);
    EXPECT_EQ(resFactory.createLandmark("Park"), nullptr);
    EXPECT_EQ(resFactory.createLandmark("Community Center"), nullptr);
    EXPECT_EQ(resFactory.createLandmark("Monument"), nullptr);
    EXPECT_EQ(resFactory.createServiceBuilding("Education"), nullptr);
    EXPECT_EQ(resFactory.createServiceBuilding("Security"), nullptr);
    EXPECT_EQ(resFactory.createServiceBuilding("Entertainment"), nullptr);
}

// Test that the Commercial factory is created
TEST_F(FactTest, CommercialFactoryCreation) {
    ASSERT_NO_THROW(FactCommercial());
}

// Test creating Commercial buildings
TEST_F(FactTest, CreateMall) {
    Commercial* building = comFactory.createComBuilding("Mall");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<ComMall*>(building) != nullptr);
    delete building;
}

TEST_F(FactTest, CreateShop) {
    Commercial* building = comFactory.createComBuilding("Shop");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<ComShop*>(building) != nullptr);
    delete building;
}

TEST_F(FactTest, CreateOffice) {
    Commercial* building = comFactory.createComBuilding("Office");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<ComOffice*>(building) != nullptr);
    delete building;
}

// Test that unsupported Commercial type returns nullptr
TEST_F(FactTest, CreateUnknownCommercialType) {
    Commercial* building = comFactory.createComBuilding("Warehouse");
    EXPECT_EQ(building, nullptr);
}

// Test that other building types return nullptr in the Commercial factory
TEST_F(FactTest, CommercialFactoryUnsupportedTypes) {
    EXPECT_EQ(comFactory.createResBuilding("House"), nullptr);
    EXPECT_EQ(comFactory.createResBuilding("Townhouse"), nullptr);
    EXPECT_EQ(comFactory.createResBuilding("Flat"), nullptr);
    EXPECT_EQ(comFactory.createResBuilding("Estate"), nullptr);
    EXPECT_EQ(comFactory.createIndBuilding("Factory"), nullptr);
    EXPECT_EQ(comFactory.createIndBuilding("Warehouse"), nullptr);
    EXPECT_EQ(comFactory.createIndBuilding("Plant"), nullptr);
    EXPECT_EQ(comFactory.createLandmark("Park"), nullptr);
    EXPECT_EQ(comFactory.createLandmark("Community Center"), nullptr);
    EXPECT_EQ(comFactory.createLandmark("Monument"), nullptr);
    EXPECT_EQ(comFactory.createServiceBuilding("Education"), nullptr);
    EXPECT_EQ(comFactory.createServiceBuilding("Security"), nullptr);
    EXPECT_EQ(comFactory.createServiceBuilding("Entertainment"), nullptr);
}

// Test that the Industrial factory is created
TEST_F(FactTest, IndustrialFactoryCreation) {
    ASSERT_NO_THROW(FactIndustrial());
}

// Test creating Industrial buildings
TEST_F(FactTest, CreateFactory) {
    Industrial* building = indFactory.createIndBuilding("Factory");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<IndFactory*>(building) != nullptr);
    delete building;
}

TEST_F(FactTest, CreateWarehouse) {
    Industrial* building = indFactory.createIndBuilding("Warehouse");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<IndWarehouse*>(building) != nullptr);
    delete building;
}

TEST_F(FactTest, CreatePlant) {
    Industrial* building = indFactory.createIndBuilding("Plant");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<IndPlant*>(building) != nullptr);
    delete building;
}

// Test that unsupported Industrial type returns nullptr
TEST_F(FactTest, CreateUnknownIndustrialType) {
    Industrial* building = indFactory.createIndBuilding("Refinery");
    EXPECT_EQ(building, nullptr);
}

// Test that other building types return nullptr in the Industrial factory
TEST_F(FactTest, IndustrialFactoryUnsupportedTypes) {
    EXPECT_EQ(indFactory.createResBuilding("House"), nullptr);
    EXPECT_EQ(indFactory.createResBuilding("Townhouse"), nullptr);
    EXPECT_EQ(indFactory.createResBuilding("Apartment"), nullptr);
    EXPECT_EQ(indFactory.createComBuilding("Mall"), nullptr);
    EXPECT_EQ(indFactory.createComBuilding("Shop"), nullptr);
    EXPECT_EQ(indFactory.createComBuilding("Office"), nullptr);
    EXPECT_EQ(indFactory.createLandmark("Park"), nullptr);
    EXPECT_EQ(indFactory.createLandmark("Community Center"), nullptr);
    EXPECT_EQ(indFactory.createLandmark("Monument"), nullptr);
    EXPECT_EQ(indFactory.createServiceBuilding("Education"), nullptr);
    EXPECT_EQ(indFactory.createServiceBuilding("Security"), nullptr);
    EXPECT_EQ(indFactory.createServiceBuilding("Entertainment"), nullptr);
}

// Test that the Landmark factory is created
TEST_F(FactTest, LandmarkFactoryCreation) {
    ASSERT_NO_THROW(FactLandmarks());
}

// Test creating Landmarks
TEST_F(FactTest, CreatePark) {
    Landmark* building = landmarkFactory.createLandmark("Park");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<LandPark*>(building) != nullptr);
    delete building;
}

TEST_F(FactTest, CreateCommunityCenter) {
    Landmark* building = landmarkFactory.createLandmark("Community Center");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<LandCCenter*>(building) != nullptr);
    delete building;
}

TEST_F(FactTest, CreateMonument) {
    Landmark* building = landmarkFactory.createLandmark("Monument");
    ASSERT_NE(building, nullptr);
    EXPECT_TRUE(dynamic_cast<LandMonument*>(building) != nullptr);
    delete building;
}

// Test that unsupported Landmark type returns nullptr
TEST_F(FactTest, CreateUnknownLandmarkType) {
    Landmark* building = landmarkFactory.createLandmark("Tower");
    EXPECT_EQ(building, nullptr);
}

// Test that other building types return nullptr in the Landmark factory
TEST_F(FactTest, LandmarkFactoryUnsupportedTypes) {
    EXPECT_EQ(landmarkFactory.createResBuilding("House"), nullptr);
    EXPECT_EQ(landmarkFactory.createResBuilding("Townhouse"), nullptr);
    EXPECT_EQ(landmarkFactory.createResBuilding("Flat"), nullptr);
    EXPECT_EQ(landmarkFactory.createResBuilding("Estate"), nullptr);
    EXPECT_EQ(landmarkFactory.createComBuilding("Mall"), nullptr);
    EXPECT_EQ(landmarkFactory.createComBuilding("Shop"), nullptr);
    EXPECT_EQ(landmarkFactory.createComBuilding("Office"), nullptr);
    EXPECT_EQ(landmarkFactory.createIndBuilding("Factory"), nullptr);
    EXPECT_EQ(landmarkFactory.createIndBuilding("Warehouse"), nullptr);
    EXPECT_EQ(landmarkFactory.createIndBuilding("Plant"), nullptr);
    EXPECT_EQ(landmarkFactory.createServiceBuilding("Education"), nullptr);
    EXPECT_EQ(landmarkFactory.createServiceBuilding("Security"), nullptr);
    EXPECT_EQ(landmarkFactory.createServiceBuilding("Entertainment"), nullptr);
}

// Test that the Service factory is created
TEST_F(FactTest, ServiceFactoryCreation) {
    ASSERT_NO_THROW(FactService());
}

// Test creating Services
TEST_F(FactTest, CreateEducationService) {
    Services* service = serviceFactory.createServiceBuilding("Education");
    ASSERT_NE(service, nullptr);
    EXPECT_TRUE(dynamic_cast<ServEducation*>(service) != nullptr);
    delete service;
}

TEST_F(FactTest, CreateSecurityService) {
    Services* service = serviceFactory.createServiceBuilding("Security");
    ASSERT_NE(service, nullptr);
    EXPECT_TRUE(dynamic_cast<ServSecurity*>(service) != nullptr);
    delete service;
}

TEST_F(FactTest, CreateEntertainmentService) {
    Services* service = serviceFactory.createServiceBuilding("Entertainment");
    ASSERT_NE(service, nullptr);
    EXPECT_TRUE(dynamic_cast<ServEntertainment*>(service) != nullptr);
    delete service;
}

// Test that unsupported service type returns nullptr
TEST_F(FactTest, CreateUnknownServiceType) {
    Services* service = serviceFactory.createServiceBuilding("Health");
    EXPECT_EQ(service, nullptr);
}

// Test that other building types return nullptr in the Service factory
TEST_F(FactTest, ServiceFactoryUnsupportedTypes) {
    EXPECT_EQ(serviceFactory.createResBuilding("House"), nullptr);
    EXPECT_EQ(serviceFactory.createResBuilding("Townhouse"), nullptr);
    EXPECT_EQ(serviceFactory.createResBuilding("Flat"), nullptr);
    EXPECT_EQ(serviceFactory.createResBuilding("Estate"), nullptr);
    EXPECT_EQ(serviceFactory.createComBuilding("Mall"), nullptr);
    EXPECT_EQ(serviceFactory.createComBuilding("Shop"), nullptr);
    EXPECT_EQ(serviceFactory.createComBuilding("Office"), nullptr);
    EXPECT_EQ(serviceFactory.createIndBuilding("Factory"), nullptr);
    EXPECT_EQ(serviceFactory.createIndBuilding("Warehouse"), nullptr);
    EXPECT_EQ(serviceFactory.createIndBuilding("Plant"), nullptr);
    EXPECT_EQ(serviceFactory.createLandmark("Park"), nullptr);
    EXPECT_EQ(serviceFactory.createLandmark("Community Center"), nullptr);
    EXPECT_EQ(serviceFactory.createLandmark("Monument"), nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
