#include <gtest/gtest.h>
#include "../include/orc.hpp"
#include "../include/squirrel.hpp"
#include "../include/druid.hpp"
#include "../include/npc.hpp"


TEST(orc_test, 01) {
    Orc orc(10, 10);
    orc.print();
}

TEST(orc_test, 02) {
    Orc orc(10, 10);
    std::cout << orc << std::endl;
}

TEST(orc_test, 03) {
    std::shared_ptr<NPC> orc = std::make_shared<Orc>(10, 10);
    
    bool fight_with_orc = orc->accept(orc);

    ASSERT_FALSE(fight_with_orc);
}

TEST(orc_test, 04) {
    std::shared_ptr<NPC> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(20, 30);

    bool fight_with_druid = druid->accept(orc);

    ASSERT_TRUE(fight_with_druid);
}

TEST(orc_test, 05) {
    std::shared_ptr<NPC> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_squirrel = squirrel->accept(orc);

    ASSERT_FALSE(fight_with_squirrel);
}

TEST(orc_test, 06) {
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(10, 10);

    bool fight_with_orc = orc->fight(orc);

    ASSERT_FALSE(fight_with_orc);
}

TEST(orc_test, 07) {
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<Druid> druid = std::make_shared<Druid>(20, 30);

    bool fight_with_druid = druid->fight(orc);

    ASSERT_FALSE(fight_with_druid);
}

TEST(orc_test, 08) {
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_squirrel = squirrel->fight(orc);

    ASSERT_FALSE(fight_with_squirrel);
}




TEST(druid_test, 01) {
    Druid druid(10, 10);
    druid.print();
}

TEST(druid_test, 02) {
    Druid druid(10, 10);
    std::cout << druid << std::endl;
}

TEST(druid_test, 03) {
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(20, 30);

    bool fight_with_druid = druid->accept(druid);

    ASSERT_FALSE(fight_with_druid);
}

TEST(druid_test, 04) {
    std::shared_ptr<NPC> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(20, 30);

    bool fight_with_orc = orc->accept(druid);

    ASSERT_FALSE(fight_with_orc);
}

TEST(druid_test, 05) {
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_squirrel = squirrel->accept(druid);

    ASSERT_TRUE(fight_with_squirrel);
}

TEST(druid_test, 06) {
    std::shared_ptr<Druid> druid = std::make_shared<Druid>(20, 30);

    bool fight_with_druid = druid->fight(druid);
    
    ASSERT_FALSE(fight_with_druid);
}

TEST(druid_test, 07) {
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<Druid> druid = std::make_shared<Druid>(20, 30);

    bool fight_with_orc = orc->fight(druid);

    ASSERT_TRUE(fight_with_orc);
}

TEST(druid_test, 08) {
    std::shared_ptr<Druid> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_squirrel = squirrel->fight(druid);

    ASSERT_FALSE(fight_with_squirrel);
}




TEST(squirrel_test, 01) {
    Squirrel squirrel(10, 10);
    squirrel.print();
}

TEST(squirrel_test, 02) {

    Squirrel squirrel(10, 10);
    std::cout << squirrel << std::endl;
}

TEST(squirrel_test, 03) {
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_squirrel = squirrel->accept(squirrel);
    
    ASSERT_FALSE(fight_with_squirrel);
}

TEST(squirrel_test, 04) {
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_druid = druid->accept(squirrel);

    ASSERT_FALSE(fight_with_druid);
}

TEST(squirrel_test, 05) {
    std::shared_ptr<NPC> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_orc = orc->accept(squirrel);

    ASSERT_FALSE(fight_with_orc);
}

TEST(squirrel_test, 06) {
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_squirrel = squirrel->fight(squirrel);

    ASSERT_FALSE(fight_with_squirrel);
}

TEST(squirrel_test, 07) {
    std::shared_ptr<Druid> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_druid = druid->fight(squirrel);

    ASSERT_TRUE(fight_with_druid);
}

TEST(squirrel_test, 08) {
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_orc = orc->fight(squirrel);

    ASSERT_FALSE(fight_with_orc);
}




int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}