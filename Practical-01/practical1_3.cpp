#include <iostream>
#include <string>
using namespace std;
int main() {
    string sen;
    cout << "Enter a sentence: ";
    getline(cin,sen);
    string word = "", longest = "";
    for (int i= 0; i<=sen.length(); i++) {
        if (i==sen.length() || sen[i] == ' ') {
            if (word.length()>longest.length()) {
                longest = word;
            }
            word="";
        }
        else {
            word+=sen[i];
        }
    }
    cout<<"Longest word: "<<longest<<endl;
    cout<<"Length:"<<longest.length();

    return 0;
}
