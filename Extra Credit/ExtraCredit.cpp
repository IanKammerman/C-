#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// Battle.h
//
// This is the declarataion of battle class
// Which has the values of botspower, botscount, and bosspower 
// Member functions calculate matrix power


class Battle{
    //Giving Mech class access to members of class Battle
    friend class Mech;
    public:
        //Constructor assigning values to members in Battle class
        Battle(int botsP[10], int botsC, float bossP);
        //Calculates total power of all enemy bots
        float matrix_power();

    private:
        //Private members of class Battle
        int botsPower[10];
        int botsCount;
        float bossPower;

};

// Battle.cpp
//
// This is the source of Battle Class
// This calculates battle power 


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


// Mech.h
//
// This is declaration of the mech class
// Takes in object from battle
// Member function calculate Micro Missiles



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

// Mech.cpp
//
// This is the source of Mech class
// This calculates the defense matrix and micro missiles


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


int main() {
//TODO: Open and read file
    //Open File
    ifstream myfile("combat.txt");

    //Initialize variables
    int botsCount;
    float bossPower;
    int microMissiles;
    float defenseMatrix;

    //Check if File open
    if (!myfile.is_open()){
        cout << "File did not open" << endl;
        return 0;
    }

    //Read data from combat.txt file
    myfile >> botsCount;
    int botsPower[10];
    for(int i = 0; i < botsCount; i++)
        myfile >> botsPower[i];
    myfile >> bossPower;

    //Close file
    myfile.close();


    //Initialize battle and dva
    Battle dvaBattle(botsPower, botsCount, bossPower);
    Mech dva;

    //Calculate power needed
    float matrixPowerRequired = dvaBattle.matrix_power();
    float missilePowerRequired = dva.micro_missile(dvaBattle);
    //Load D.Va
    dva.load(matrixPowerRequired, missilePowerRequired);
//TODO: Open and write results to file
    //Open a new file with the intent to write into the txt file
    ofstream combatfile;
    combatfile.open("report.txt");

    //Check if combatfile is open
    if (!combatfile.is_open()){
        cout << "File did not open" << endl;
        return 0;
    }
    //Write the report and close file after
    combatfile << "D.Va's Combat Report \n";
    combatfile << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << setprecision(2) << fixed << bossPower << ".\n";
    combatfile << "Loaded mech with " << dva.getmicroMissiles() << " micro missiles and the defense matrix with power " << setprecision(2) << fixed << dva.getDefenseMatrix() << ".\n";
    combatfile << "Ready for Combat!";
    combatfile.close();
return 0;
}

