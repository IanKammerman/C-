#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "This is a linesss";
    string output = "";
    int text_size = text.size(); //get length of string
    for (int i = 0; i < text_size; i++) {
        if (text[i] != 's') { //string comparison
            output += text[i]; //append to a string
        }
    }
    cout << output << endl;
    return 0;
}