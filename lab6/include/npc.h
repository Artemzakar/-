#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include "observer.h"

class NPC;
class Princess;
class Dragon;
class Knight;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {Unknown, PrincessType, DragonType, KnightType};

class Visitor;

class NPC{
public:
    NpcType type;
    int x{0}, y{0};
    std::string name;
    std::vector<std::shared_ptr<IObserver>> observers;

    NPC(NpcType t, int _x, int _y,std::string &_name);
    NPC(NpcType t,std::ifstream &is,std::string &_name);
    NPC(NPC& other);
    NPC(NPC* other);
    virtual ~NPC();

    bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;
    void notify(NPC* attacker, bool win);

    virtual void get_name(std::ofstream &os){};
    virtual void accept(std::shared_ptr<NPC> attacker,Visitor& visitor){};
    virtual void attach(std::shared_ptr<IObserver> observer){};
    virtual void detach(std::shared_ptr<IObserver> observer){};
    virtual void print(){};

    virtual void save(std::ofstream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};

#endif //NPC_H