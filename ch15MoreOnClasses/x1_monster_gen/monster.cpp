#include "monster.hpp"
#include "randgen.hpp"
#include <cstdint>
#include <string_view>

constexpr Monster::Monster(const Monster& other)
    : type_{other.type_}
    , name_{other.name_}
    , roar_{other.roar_}
    , hitPoints_{other.hitPoints_}
{
}

constexpr Monster::Monster(Monster::Type type,
                           Monster::Name_t name,
                           Monster::Roar_t roar,
                           Monster::HitPoint_t hitPoints)
    : type_{type}
    , name_{name}
    , roar_{roar}
    , hitPoints_{hitPoints}
{
}

Monster::Monster() {
    *this = Monster::randGenerate();
}

std::string_view Monster::getTypeString() const {
    switch (type_) {
    case dragon:    return "dragon";
    case goblin:    return "goblin";
    case ogre:      return "ogre";
    case orc:       return "orc";
    case skeleton:  return "skeleton";
    case troll:     return "troll";
    case vampire:   return "vampire";
    case zombie:    return "zombie";
    default:        return "???unknown???";
    }
}


const Monster& Monster::print() const {
    std::cout << name_ << " the " << getTypeString();
    if (hitPoints_)
        std::cout << " has " << hitPoints_ << " hit points and says " << roar_ << '\n';
    else
        std::cout << "is dead\n";
    return *this;
}

Monster::Name_t Monster::getName(uint8_t n) {
    switch(n) {
    case 0:  return "Blarg";
    case 1:  return "Moog";
    case 2:  return "Pksh";
    case 3:  return "Tyrn";
    case 4:  return "Mort";
    case 5:  return "Hans";
    default: return "???";
    }
}

Monster::Roar_t Monster::getRoar(uint8_t n) {
    switch(n) {
    case 0:  return "*ROAR*";
    case 1:  return "*peep*";
    case 2:  return "*squeal*";
    case 3:  return "*whine*";
    case 4:  return "*growl*";
    case 5:  return "*burp*";
    default: return "???";
    }
}

Monster Monster::randGenerate() {
    return Monster{static_cast<Monster::Type>(Randgen::get(0, Monster::maxMonsterTypes-1)),
                   getName(static_cast<uint8_t>(Randgen::get(0, 5))),
                   getRoar(static_cast<uint8_t>(Randgen::get(0, 5))),
                   static_cast<Monster::HitPoint_t>(Randgen::get(0, 100))};
}
