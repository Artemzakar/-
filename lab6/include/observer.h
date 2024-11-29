#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <memory>
#include <fstream>

class NPC;

class IObserver{
public:
    IObserver() = default;
    virtual ~IObserver();
     virtual void on_fight(NPC*attacker,NPC* defender, bool win) = 0;
};

class ConsoleObserver: public IObserver {
public:
    ConsoleObserver() = default;
    void on_fight(NPC* attacker,NPC* defender, bool win) override;
};

class FileObserver: public IObserver {
public:
    std::ofstream in;
    std::string filename;
    FileObserver() = default;
    FileObserver(std::string &_filename);
    FileObserver(FileObserver &other);
    FileObserver(FileObserver &&other);
    ~FileObserver();
    void on_fight(NPC* attacker,NPC* defender, bool win) override;
};

#endif // OBSERVER_H