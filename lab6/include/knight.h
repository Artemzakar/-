#ifndef KNIGHT_H
#define KNIGHT_H

#include "npc.h"

struct Knight : public NPC
{
    Knight(int x, int y,std::string &_name);
    Knight(std::ifstream &is,std::string &_name);

    void print() override;
    void save(std::ofstream &os) override;

    void get_name(std::ofstream &os) override;

    void accept(std::shared_ptr<NPC> attacker,Visitor& visitor);

    void attach(std::shared_ptr<IObserver> observer) override;
    void detach(std::shared_ptr<IObserver> observer) override;
    
    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};

#endif // KNIGHT_H