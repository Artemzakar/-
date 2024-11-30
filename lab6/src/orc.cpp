#include "../include/orc.hpp"
#include "../include/druid.hpp"
#include "../include/squirrel.hpp"

Orc::Orc(int x, int y) : NPC(OrcType, x, y) {}
Orc::Orc(std::istream &is) : NPC(OrcType, is) {}

void Orc::print()
{
    std::cout << *this;
}

void Orc::save(std::ostream &os)
{
    os << OrcType << std::endl;
    NPC::save(os);
}

void Orc::print(std::ostream &outfs) {
    outfs << *this;
}

bool Orc::accept(std::shared_ptr<NPC> visitor) {
    std::shared_ptr<Orc> This = std::make_shared<Orc>(*this);
    return visitor->visit(This);
}

bool Orc::fight(std::shared_ptr<Squirrel> other)
{
    fight_notify(other, false);
    return false;
}

bool Orc::fight(std::shared_ptr<Orc> other)
{
    fight_notify(other, false);
    return false;
}

bool Orc::fight(std::shared_ptr<Druid> other)
{
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, Orc &orc)
{
    os << "Orc" << *static_cast<NPC *>(&orc) << std::endl;
    return os;
}