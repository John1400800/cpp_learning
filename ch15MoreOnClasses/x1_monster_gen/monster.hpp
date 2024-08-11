#ifndef MONSTER_H
#define MONSTER_H
#include <cstdint>
#include <string_view>
#include <string>
#include <iostream>

class Monster {
public:
    using HitPoint_t = uint32_t;
    using Roar_t = std::string_view;
    using Name_t = std::string_view;
    enum Type {
        dragon, goblin, ogre, orc,
        skeleton, troll, vampire, zombie,
        maxMonsterTypes,
    };
private:
    Type type_{};
    std::string name_{"???"};
    std::string roar_{"???"};
    HitPoint_t hitPoints_{};
public:
    constexpr Monster(const Monster& other);
    explicit Monster(); // generate random monster used Monster::randGenerate()
    explicit constexpr Monster(Type type,
                               Name_t name,
                               Roar_t roar,
                               HitPoint_t hitPoints);
    std::string_view getTypeString() const;
    const Monster& print() const;
    static Name_t getName(uint8_t n=0);
    static Roar_t getRoar(uint8_t n=0);
    static Monster randGenerate();
};

#endif//MONSTER_H
