#include "../include/dragon.h"
#include "../include/knight.h"
#include "../include/princess.h"
#include <algorithm>

Princess::Princess(int x, int y,std::string &_name) :  NPC(PrincessType, x, y, _name) {}

Princess::Princess(std::ifstream &is,std::string &_name) : NPC(PrincessType, is, _name) {}

Princess::~Princess() {}

void Princess::print()
{
    std::cout << *this;
}

void Princess::save(std::ofstream &os){
    os << PrincessType << std::endl;
    NPC::save(os);
}

void Princess::get_name(std::ofstream &os){
    os << this->name << " " << "{x: " << this->x << "; y:" << this->y << "}" << std::endl;
}

void Princess::attach(std::shared_ptr<IObserver> observer) {
    NPC::observers.push_back(observer);
}
void Princess::detach(std::shared_ptr<IObserver> observer) {
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream &operator<<(std::ostream &os, Princess &princess)
{
    os << "princess: " << *static_cast<NPC*>(&princess) << std::endl;
    return os;
}