#pragma once

#include "npc.hpp"
#include "squirrel.hpp"
#include "orc.hpp"
#include "druid.hpp"

#include <sstream>
#include <atomic>
#include <thread>
#include <optional>
#include <array>
#include <chrono>
#include <queue>
#include <mutex>

struct IFightObserver{
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender, bool win) = 0;
};



class TextObserver : public IFightObserver
{
private:
    TextObserver(){};

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {
            std::cout << std::endl
                      << "Murder --------" << std::endl;
            std::cout << "Killer: ";
            attacker->print();
            std::cout << "Victim: ";
            defender->print();
        }
    }
};




class F_Observer : public IFightObserver
{
private:
    std::ofstream file;

    F_Observer()
    {
        file.open("log.txt");
    }

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static std::shared_ptr<IFightObserver> instance(new F_Observer());
        return instance;
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {
            file << std::endl
                 << "Murder --------" << std::endl;
            file << "Killer: ";
            attacker->print(file);
            file << "Victim: ";
            defender->print(file);
        }
    }
};