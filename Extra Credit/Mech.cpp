// Mech.cpp
//
// This is the source of Mech class
// This calculates the defense matrix and micro missiles

#include "mech.h"
#include <cmath>

//Constructor assigning starting values to defenseMatrix and microMissiles
Mech::Mech():defenseMatrix(100.00), microMissiles(10){}

//Load function that will overload the values of matrixPowerRequired and microMissiles if more is needed
void Mech::load(float& matrixPowerRequired, float& missilePowerRequired){
    if(defenseMatrix > matrixPowerRequired)
        matrixPowerRequired = defenseMatrix;
    else
        defenseMatrix = matrixPowerRequired;
    float microNeeded = 0;
    microNeeded = missilePowerRequired / 60;
    if(microMissiles < microNeeded)
        microMissiles = ceil(microNeeded);
    else
        microMissiles = 10;
}

//Calculates the total missile power required
float Mech::micro_missile(Battle& dva){
    float total = 0;
    for (int i = 0; i < dva.botsCount; i++)
        total += dva.botsPower[i] * 2;
    total += dva.bossPower * 5;
    return total;
        }

//Getter function for defenseMatrix
float Mech::getDefenseMatrix() const{
    return defenseMatrix;
}

//Getter function for microMissiles
int Mech::getmicroMissiles() const{
    return microMissiles;
}