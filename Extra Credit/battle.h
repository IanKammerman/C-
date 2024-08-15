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