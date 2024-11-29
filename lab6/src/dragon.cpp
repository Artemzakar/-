#include "../include/dragon.h"
#include "../include/knight.h"
#include "../include/princess.h"
#include <algorithm>

Dragon::Dragon(int x, int y,std::string &_name) : NPC(DragonType, x, y, _name) {}

Dragon::Dragon(std::ifstream &is,std::string &_name) : NPC(DragonType, is, _name) {}

void Dragon::print()
{
    std::cout << *this;
}

void Dragon::attach(std::shared_ptr<IObserver> observer) {
    NPC::observers.push_back(observer);
}
void Dragon::detach(std::shared_ptr<IObserver> observer) {
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

void Dragon::save(std::ofstream &os) 
{
    os << DragonType << std::endl;
    NPC::save(os);
}

void Dragon::get_name(std::ofstream &os){
    os << this->name << " " << "{x: " << this->x << "; y:" << this->y << "}" << std::endl;
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}