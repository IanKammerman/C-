#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

//Function Prototype
float matrix_power(int botsPower[], int botsCount, float bossPower);
void load_dva(float& defenseMatrix, float& matrixPowerRequired);
void load_dva(int& microMissiles, float& missilePowerRequired);

//Calculates total power needed
float matrix_power(int botsPower[], int botsCount, float bossPower){
    float totalPower = 0;
    for(int i = 0; i < botsCount; i++)
        totalPower += botsPower[i];
    totalPower += bossPower;
    return totalPower;
}

//Calculates how much missile power is needed
template <typename T>
T single_missile_power(T a){
    T b = 0;
    if(a <= 15)
        b = a * 2;
    else
        b = a * 5;
    return b;
}

//Load Defense Matrix
void load_dva(float& defenseMatrix, float& matrixPowerRequired){
    if(defenseMatrix > matrixPowerRequired)
        matrixPowerRequired = defenseMatrix;
}

//Load Micro Missiles 
void load_dva(int& microMissiles, float& missilePowerRequired){
    float microNeeded = 0;
    microNeeded = missilePowerRequired / 60;
    if(microMissiles < microNeeded)
        microMissiles = ceil(microNeeded);
}

//Main Function
int main(){
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
    int botsPower[botsCount];
    for(int i = 0; i < botsCount; i++)
        myfile >> botsPower[i];
    myfile >> bossPower;
    myfile >> microMissiles;
    myfile >> defenseMatrix;

        //Close file
    myfile.close();

    //Finds the value of matrix power required
    float matrixPowerRequired = 0;
    matrixPowerRequired = matrix_power(botsPower, botsCount, bossPower);

    //Finds the missile power required
    float missilePowerRequired = 0;
    for(int i = 0; i < botsCount; i++)
        missilePowerRequired += single_missile_power(botsPower[i]);
    missilePowerRequired += single_missile_power(bossPower);

    //Run Load dva
    load_dva(defenseMatrix, matrixPowerRequired);
    load_dva(microMissiles, missilePowerRequired);

    //Open a new file with the intent to write into the txt file
    ofstream combatfile;
    combatfile.open("report.txt");

    //Check if combatfile is open
    if (!combatfile.is_open()){
        cout << "File did not open" << endl;
        return 0;
    }
    //Write the report
    combatfile << "D.Va's Combat Report \n";
    combatfile << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << setprecision(2) << fixed << bossPower << ".\n";
    combatfile << "Loaded mech with " << microMissiles << " micro missiles and the defense matrix with power " << setprecision(2) << fixed << matrixPowerRequired << ".\n";
    combatfile << "Ready for Combat!";
    combatfile.close();
}
