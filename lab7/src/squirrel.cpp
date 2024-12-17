#include "../include/squirrel.hpp"
#include "../include/orc.hpp"
#include "../include/druid.hpp"

Squirrel::Squirrel(int x, int y) : NPC(SquirrelType, x, y) {}
Squirrel::Squirrel(std::istream &is) : NPC(SquirrelType, is) {}

void Squirrel::print()
{
    std::cout << *this;
}

void Squirrel::save(std::ostream &os)
{
    os << SquirrelType << std::endl;
    NPC::save(os);
}

void Squirrel::print(std::ostream &outfs) {
    outfs << *this;
}

bool Squirrel::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Squirrel>(this,[](Squirrel*){}));
}

bool Squirrel::fight(std::shared_ptr<Druid> other)
{
    fight_notify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Orc> other)
{
    fight_notify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Squirrel> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Squirrel &squirrel)
{
    os << "Squirrel" << *static_cast<NPC *>(&squirrel) << std::endl;
    return os;
}