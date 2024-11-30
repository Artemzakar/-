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
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_druid = druid->accept(orc);
    bool fight_with_squirrel = squirrel->accept(orc);
    bool fight_with_orc = orc->accept(orc);

    ASSERT_TRUE(fight_with_druid);
    ASSERT_FALSE(fight_with_squirrel);
    ASSERT_FALSE(fight_with_orc);
}

TEST(orc_test, 04) {
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<Druid> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_druid = druid->fight(orc);
    bool fight_with_squirrel = squirrel->fight(orc);
    bool fight_with_orc = orc->fight(orc);

    ASSERT_FALSE(fight_with_druid);
    ASSERT_FALSE(fight_with_squirrel);
    ASSERT_FALSE(fight_with_orc);
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
    std::shared_ptr<NPC> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_druid = druid->accept(druid);
    bool fight_with_squirrel = squirrel->accept(druid);
    bool fight_with_orc = orc->accept(druid);

    ASSERT_FALSE(fight_with_druid);
    ASSERT_TRUE(fight_with_squirrel);
    ASSERT_FALSE(fight_with_orc);
}

TEST(druid_test, 04) {
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<Druid> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_druid = druid->fight(druid);
    bool fight_with_squirrel = squirrel->fight(druid);
    bool fight_with_orc = orc->fight(druid);

    ASSERT_FALSE(fight_with_druid);
    ASSERT_FALSE(fight_with_squirrel);
    ASSERT_TRUE(fight_with_orc);
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
    std::shared_ptr<NPC> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<NPC> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_druid = druid->accept(squirrel);
    bool fight_with_squirrel = squirrel->accept(squirrel);
    bool fight_with_orc = orc->accept(squirrel);

    ASSERT_FALSE(fight_with_druid);
    ASSERT_FALSE(fight_with_squirrel);
    ASSERT_FALSE(fight_with_orc);
}

TEST(squirrel_test, 04) {
    std::shared_ptr<Orc> orc = std::make_shared<Orc>(10, 10);
    std::shared_ptr<Druid> druid = std::make_shared<Druid>(20, 30);
    std::shared_ptr<Squirrel> squirrel = std::make_shared<Squirrel>(100, 100);

    bool fight_with_druid = druid->fight(squirrel);
    bool fight_with_squirrel = squirrel->fight(squirrel);
    bool fight_with_orc = orc->fight(squirrel);

    ASSERT_TRUE(fight_with_druid);
    ASSERT_FALSE(fight_with_squirrel);
    ASSERT_FALSE(fight_with_orc);
}




int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}