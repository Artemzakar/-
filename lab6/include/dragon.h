#ifndef DRAGON_H
#define DRAGON_H

#include "npc.h"

struct Dragon : public NPC
{
    Dragon(int x, int y,std::string &_name);
    Dragon(std::ifstream &is,std::string &_name);

    void print() override;

    void accept(std::shared_ptr<NPC> attacker,Visitor& visitor);

    void get_name(std::ofstream &os) override;

    void attach(std::shared_ptr<IObserver> observer) override;
    void detach(std::shared_ptr<IObserver> observer) override;

    void save(std::ofstream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};

#endif // DRAGON_H