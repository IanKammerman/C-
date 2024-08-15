// Battle.cpp
//
// This is the source of Battle Class
// This calculates battle power 

#include "battle.h"

//Constructor assigning values to botsPower[i], botsCount, and bossPower in class Battle
Battle::Battle(int botsP[10], int botsC, float bossP){
    for(int i = 0; i < botsC; i++)
        botsPower[i] = botsP[i];
    botsCount = botsC;
    bossPower = bossP;
        }

//Calculates total power of all bots
float Battle::matrix_power(){
    float totalPower = 0;
    for(int i = 0; i < botsCount; i++)
        totalPower += botsPower[i];
    totalPower += bossPower;
    return totalPower;
}

