#include "../include/observer.h"
#include "../include/npc.h"

IObserver::~IObserver(){}

void ConsoleObserver::on_fight(NPC* attacker,NPC* defender, bool win) {
    if (win){
        std::cout << std::endl << "-------- Murder --------" << std::endl;
        std::cout << "attaker -> ";
        attacker->print();
        std::cout << "defender -> ";
        defender->print();
    }
}

FileObserver::FileObserver(std::string &_filename) : filename(_filename){
    in.open(filename);
}

FileObserver::FileObserver(FileObserver &other) : FileObserver(other.filename){}

FileObserver::FileObserver(FileObserver &&other) : FileObserver(other.filename){}

FileObserver::~FileObserver(){
    in.close();
}

void FileObserver::on_fight(NPC* attacker,NPC* defender, bool win) {
    if(in.is_open()){
        if (win){
            in << std::endl << "-------- Murder --------" << std::endl;
            in << "attaker -> ";
            attacker->get_name(in);
            in << "defender -> ";
            defender->get_name(in);
        }
    }
    
}