#include <iostream>
#include <string>
using namespace std;

char get_index(string s, int i){
    char letter = s[i];
    return letter; 
}

int main() {
    string text = "This is a linesss";
    string output = "";
    int text_size = text.size(); //get length of string
    for (int i = 0; i < text_size; i++) {
        char t = get_index(text, i);
        if (text[i] != 's') { //string comparison
            output += text[i]; //append to a string
        }
    }
    cout << output << endl;
    return 0;
}