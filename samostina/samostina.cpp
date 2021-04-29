#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;

void noalpha() {
    string word;
    while(cin>>word)
    {
        for (int i = 0; i < word.length(); i++) {
            if (!isalpha(word[i])) {
                cout << word[i];
            }
        }
    }
}
void second() {
    string word,stt;
    ifstream in("in.txt");
    while (in >> word) {
        word[0] = toupper(word[0]);
        stt += word;
    }
    cout << stt;
    in.close();
}
int main()
{
    noalpha();
    second();
}
