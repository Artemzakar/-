#include "include/npc.hpp"
#include "include/squirrel.hpp"
#include "include/orc.hpp"
#include "include/druid.hpp"




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




std::shared_ptr<NPC> factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case SquirrelType:
            result = std::make_shared<Squirrel>(is);
            break;
        case OrcType:
            result = std::make_shared<Orc>(is);
            break;
        case DruidType:
            result = std::make_shared<Druid>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());
        result->subscribe(F_Observer::get());

    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case SquirrelType:
        result = std::make_shared<Squirrel>(x, y);
        break;
    case OrcType:
        result = std::make_shared<Orc>(x, y);
        break;
    case DruidType:
        result = std::make_shared<Druid>(x, y);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(TextObserver::get());
        result->subscribe(F_Observer::get());

    return result;
}




void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}




std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}




// Visitor
set_t fight(const set_t &array, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success{false};

                success = defender->accept(attacker);
                
                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}




int main()
{
    set_t array; // монстры

    // Генерируем начальное распределение монстров
    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 40; ++i)
        array.insert(factory(NpcType(std::rand() % 3 + 1),
                             std::rand() % 500,
                             std::rand() % 500)); // х и у до 500

    std::cout << "Saving ... " << std::endl;
    save(array, "npc.txt");

    std::cout << "Loading ... " << std::endl;
    array = load("npc.txt");

    std::cout << "Starting position: " << array << std::endl;

    std::cout << "Fighting ... " << std::endl;
    for (size_t distance = 20; (distance <= 100) && !array.empty(); distance += 10){
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list){
            array.erase(d);
        }

        std::cout << std::endl << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;
        
    }

    std::cout << "Survivors: " << std::endl << array;

    return 0;
}