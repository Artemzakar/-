#include "../include/npc.h"

NPC::NPC(NpcType t, int _x, int _y,std::string &_name) : type(t), x(_x), y(_y), name(_name) {}

NPC::NPC(NpcType t,std::ifstream &is,std::string &_name): type(t), name(_name)
{
    is >> x;
    is >> y;
}

NPC::NPC(NPC& other) : type(other.type), x(other.x),y(other.y){}

NPC::NPC(NPC* other) : type(other->type), x(other->x),y(other->y){}

NPC::~NPC(){}

void NPC::notify(NPC* attacker, bool win) {
    //std::shared_ptr<NPC> defender = std::make_shared<NPC>(*this);
    if (win) {
        for (auto &elem : NPC::observers) {
            elem->on_fight(attacker,this, win);
        }
    }
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const
{
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

void NPC::save(std::ofstream &os)
{
    os << x << std::endl;
    os << y << std::endl;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << "name = " << npc.name << " { x:" << npc.x << ", y:" << npc.y << "} ";
    return os;
}