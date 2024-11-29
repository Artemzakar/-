#include <gtest/gtest.h>
#include <memory>
#include "../include/observer.h"
#include "../include/npc.h"
#include "../include/princess.h"
#include "../include/dragon.h"
#include "../include/knight.h"

bool success;

class Visitor{
public:
    virtual int visit(Princess* element) = 0;
    virtual int visit(Dragon* element) = 0;
    virtual int visit(Knight* element) = 0;
};

class ConcreteVisitor1 : public Visitor {
public:

    int visit(Princess* element) override {
        //std::cout << "VisitPrincess\n";
        return 1;
    }
    
    int visit(Dragon* element) override {
        //std::cout << "visitDragon\n";
        return 2;
    }

    int visit(Knight* element) override {
        //std::cout << "visitKinght\n";
        return 3;
    }
};

void Princess::accept(std::shared_ptr<NPC> attacker, Visitor& visitor) {
    int res = 0;
    if(dynamic_cast<Dragon*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Dragon*>(attacker.get()));
    
    if(res == 2) success = true;
}

void Dragon::accept(std::shared_ptr<NPC> attacker,Visitor& visitor) {
    int res = 0;
    if(dynamic_cast<Knight*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Knight*>(attacker.get()));
    
    if(res == 3) success = true;
}

void Knight::accept(std::shared_ptr<NPC> attacker,Visitor& visitor) {}

TEST(test_01, princess_constructor){
    int x{100};
    int y{100};
    std::string name{"Princess_1"};

    std::shared_ptr<NPC> a = std::make_shared<Princess>(x,y,name);


    EXPECT_EQ(100,a->x);
}

TEST(test_02, princess_constructor){
    int x{100};
    int y{100};
    std::string name{"Princess_1"};

    std::shared_ptr<NPC> a = std::make_shared<Princess>(x,y,name);


    EXPECT_EQ(100,a->y);
}

TEST(test_03, princess_constructor){
    int x{100};
    int y{100};
    std::string name{"Princess_1"};

    std::shared_ptr<NPC> a = std::make_shared<Princess>(x,y,name);


    EXPECT_EQ("Princess_1",a->name);
}

TEST(test_04, dragon_constructor){
    int x{100};
    int y{100};
    std::string name{"Dragon_1"};

    std::shared_ptr<NPC> a = std::make_shared<Dragon>(x,y,name);


    EXPECT_EQ(100,a->x);
}

TEST(test_05, dragon_constructor){
    int x{100};
    int y{100};
    std::string name{"Dragon_1"};

    std::shared_ptr<NPC> a = std::make_shared<Dragon>(x,y,name);


    EXPECT_EQ(100,a->y);
}

TEST(test_06, dragon_constructor){
    int x{100};
    int y{100};
    std::string name{"Dragon_1"};

    std::shared_ptr<NPC> a = std::make_shared<Dragon>(x,y,name);


    EXPECT_EQ("Dragon_1",a->name);
}

TEST(test_07, knight_constructor){
    int x{100};
    int y{100};
    std::string name{"Knight_1"};

    std::shared_ptr<NPC> a = std::make_shared<Knight>(x,y,name);


    EXPECT_EQ(100,a->x);
}

TEST(test_08, knight_constructor){
    int x{100};
    int y{100};
    std::string name{"Knight_1"};

    std::shared_ptr<NPC> a = std::make_shared<Knight>(x,y,name);


    EXPECT_EQ(100,a->y);
}

TEST(test_09, knight_constructor){
    int x{100};
    int y{100};
    std::string name{"Knight_1"};

    std::shared_ptr<NPC> a = std::make_shared<Knight>(x,y,name);


    EXPECT_EQ("Knight_1",a->name);
}

TEST(test_10, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Knight_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Dragon_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Dragon>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_TRUE(success);
}

TEST(test_11, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Knight_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Princess_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Princess>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_12, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Knight_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Knight_2"};

    std::shared_ptr<NPC> defender = std::make_shared<Knight>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_13, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Dragon_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Dragon>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Knight_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Knight>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_14, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Dragon_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Dragon>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Princess_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Princess>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_TRUE(success);
}

TEST(test_15, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Dragon_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Dragon>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Dragon_2"};

    std::shared_ptr<NPC> defender = std::make_shared<Dragon>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_16, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Princess_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Princess>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Princess_2"};

    std::shared_ptr<NPC> defender = std::make_shared<Princess>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_17, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Princess_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Princess>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Dragon_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Dragon>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_18, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Princess_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Princess>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Knight_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Knight>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}