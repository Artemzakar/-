#pragma once

#include "npc.hpp"
#include "squirrel.hpp"
#include "orc.hpp"
#include "druid.hpp"
#include "observer.hpp"

#include <sstream>
#include <atomic>
#include <thread>
#include <optional>
#include <array>
#include <chrono>
#include <queue>
#include <mutex>
#include <memory>

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