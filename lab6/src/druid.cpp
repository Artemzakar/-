#include "../include/orc.hpp"
#include "../include/druid.hpp"
#include "../include/squirrel.hpp"

Druid::Druid(int x, int y) : NPC(DruidType, x, y) {}
Druid::Druid(std::istream &is) : NPC(DruidType, is) {}

void Druid::print()
{
    std::cout << *this;
}

void Druid::print(std::ostream &outfs) {
    outfs << *this;
}

bool Druid::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Druid> This = std::make_shared<Druid>(*this);
    return visitor->visit(This);
}

bool Druid::fight(std::shared_ptr<Druid> other) 
{
    fight_notify(other, false);
    return false;
}

bool Druid::fight(std::shared_ptr<Squirrel> other) 
{
    fight_notify(other, true);
    return true;
}

bool Druid::fight(std::shared_ptr<Orc> other) 
{
    fight_notify(other, false);
    return false;
}

void Druid::save(std::ostream &os) 
{
    os << DruidType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Druid &druid)
{
    os << "Druid" << *static_cast<NPC *>(&druid) << std::endl;
    return os;
}