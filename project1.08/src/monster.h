//
// Created by joelm on 2016-02-23.
//

#ifndef PROJECT_MONSTER_H
#define PROJECT_MONSTER_H

#include <inttypes.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "dice_set.h"
#include "monster_descrip.h"
#include "item_descrip.h"

#define MONSTER_MIN_SPEED 5
#define MONSTER_MAX_SPEED 20

#define MONSTER_INTELLIGENT 0x8
#define MONSTER_TELEPATHIC 0x4
#define MONSTER_TUNNELING 0x2
#define MONSTER_ERRATIC 0x1

typedef struct gridCell_struct gridCell_t;
typedef struct dungeon_struct dungeon_t;

class monster {
public:
    //int speed;
    int x;
    int y;
    int lastPCX;
    int lastPCY;
    bool alive = true;

    std::string name;
    std::string description;
    int color;
    int speed;
    int abilities;
    int HP;
    dice_set* DAM_ptr;
    char symb;

public:
    monster(std::string name, std::string desc, int color, int speed, int abil, int HP, dice_set* DAM_ptr, char SYMB) {
        this->name = name;
        this->description = desc;
        this->color = color;
        this->speed = speed;
        this->abilities = abil;
        this->HP = HP;
        this->DAM_ptr = DAM_ptr;
        this->symb = SYMB;

        this->lastPCX = 0;
        this->lastPCY = 0;
        this->x = 0;
        this->y = 0;
    }
    virtual ~monster() {};
    char* toString(dungeon_t* dungeonPtr);
    // Override getChar
    virtual char getChar() = 0;
    virtual bool isPC() = 0;
};

class monster_evil : public monster {
public:
    monster_evil(std::string name, std::string desc, int color, int speed, int abil, int HP, dice_set* DAM_ptr, char SYMB)
            : monster::monster(name, desc, color, speed, abil, HP, DAM_ptr, SYMB) {}
    char getChar();
    bool isPC() { return false; }
};

class monster_PC : public monster {
public:
    gridCell_t** gridKnown;
    inline char getChar() { return '@'; }

    monster_PC(int x, int y);
    ~monster_PC();
public:
    bool isPC() { return true; }
    void updateGridKnown(gridCell_t** world);
};

//TODO below is C exports to remove

typedef struct dungeon_struct dungeon_t;

void initMonsters(dungeon_t *dungeonPtr, std::vector<monster_descrip*>& monster_descrips);
void initItems(dungeon_t& dungeon, std::vector<item_descrip*>& item_descrips);
void monstersDestroy(dungeon_t *dungeonPtr);
void itemsDestroy(dungeon_t& dungeon);
//char monsterGetChar(monster_t* m);
void monsterList(dungeon_t *dungeonPtr);
//char *monsterDescription(dungeon_t *dungeonPtr, monster_t *monsterPtr);
//int monsterGetX(monster_t* monsterRef);
//int monsterGetY(monster_t* monsterRef);
//int monsterGetLastPCX(monster_t* monsterPtr);
//int monsterGetLastPCY(monster_t* monsterPtr);
//void monsterSetX(monster_t* monsterPtr, int x);
//void monsterSetY(monster_t* monsterPtr, int x);
//void monsterSetLastPCX(monster_t* monsterPtr, int x);
//void monsterSetLastPCY(monster_t* monsterPtr, int x);
//int monsterIsAlive(monster_t* monsterRef);
//int monsterIsPC(monster_t* monsterRef);
//int monsterSpeed(monster_t* monsterPtr);
//void monsterKill(monster_t* monsterPtr);
//uint8_t monsterGetType(monster_t* monsterPtr);
//void monsterUpdatePCGridKnown(monster_t* monsterPtr, gridCell_t** world);
//gridCell_t** monsterGetPCGridKnown(monster_t* monsterPtr);

#endif //PROJECT_MONSTER_H
