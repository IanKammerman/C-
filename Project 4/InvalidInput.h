// InvalidInput.h
//
// This is the declarataion of exception class InvalidInput
// This class will return an error message if an input is invalid

#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H
#include <iostream>
#include <string>
using namespace std;

class InvalidInput{
//Public members of class InvalidInput
    public:
        InvalidInput(const string& input) : message("Invalid input \"" + input + "\".\n"){};
// Function to output the message
        void reason() const{cout << message;}
//Private members of class InvalidInput
    private:
        string message;
};

#endif