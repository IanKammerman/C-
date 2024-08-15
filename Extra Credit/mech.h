// Mech.h
//
// This is declaration of the mech class
// Takes in object from battle
// Member function calculate Micro Missiles

#include "battle.h"

class Mech{
    public:
        //Mech constructor
        Mech();
        //Calculates missile power required taking in values from class battle
        float micro_missile(Battle& x);
        //Load function that will overload values if more power is needed
        void load(float& matrixPowerRequired, float& missilePowerRequired);
        //Getter Functions
        float getDefenseMatrix() const;
        int getmicroMissiles() const;

    private:
        //Two private members
        float defenseMatrix;
        int microMissiles;
};