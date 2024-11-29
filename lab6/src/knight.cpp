#include "../include/dragon.h"
#include "../include/knight.h"
#include "../include/princess.h"
#include <algorithm>

Knight::Knight(int x, int y,std::string &_name) : NPC(KnightType, x, y,_name) {}

Knight::Knight(std::ifstream &is,std::string &_name) : NPC(KnightType, is, _name) {}

void Knight::print()
{
    std::cout << *this;
}

void Knight::save(std::ofstream &os)
{
    os << KnightType << std::endl;
    NPC::save(os);
}

void Knight::get_name(std::ofstream &os){
    os << this->name << " " << "{x: " << this->x << "; y:" << this->y << "}" << std::endl;
}

void Knight::attach(std::shared_ptr<IObserver> observer) {
    NPC::observers.push_back(observer);
}
void Knight::detach(std::shared_ptr<IObserver> observer) {
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}