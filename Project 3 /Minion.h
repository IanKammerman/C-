// Minion.h
//
// This is the declarataion of minion class
// Which has the values of name, height, eyes, bananasOwned, and minionCount 
// Member functions calculate find the tallest minion, minion count, and banana count

#ifndef Minion_H
#define Minion_H

class Minion{
//Non-member function for output
    friend ostream& operator<<(ostream&, const Minion&);

//Public members of class Minion
    public:
        Minion(string N, float H, int E, int Bananas);
        bool operator>(const Minion&) const; 
        bool operator<(const Minion&) const;
        static void printMinionCount();
        Minion &operator++();
        Minion operator++(int);
        int getBananas() const;
        string getName() const;

//Private members of class Minion
    private:
        string name;
        float height;
        int eyes;
        int bananasOwned;
        static int minionCount;
};

#endif