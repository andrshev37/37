#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Books
{
    string name;
    string avtr;
    int date;
    string janr;
};

int main()
{
    char* str = new char[1024];
    ifstream fin("in.txt");
    int n = 0;
    while (!fin.eof())
    {
        fin.getline(str, 1024, '\n');
        n++;
    }
    Books s[100], temp;
   
    
    for (int i = 0; i < n; i++) {
        fin >> s[i].name >> s[i].avtr >> s[i].date >> s[i].janr;
    }

    fin.close();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i].name < s[j].name)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
    cout << endl;
    ofstream fout("out.txt");
    for(int i = 0; i < n; i++) {

        fout << s[i].name << s[i].avtr << s[i].date << s[i].janr;
    }
    fout.close();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i].janr < s[j].janr)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
    cout << endl;
    ofstream fout("out2.txt");
    for (int i = 0; i < n; i++) {

        fout << s[i].name << s[i].avtr << s[i].date << s[i].janr;
    }
    fout.close();
}



