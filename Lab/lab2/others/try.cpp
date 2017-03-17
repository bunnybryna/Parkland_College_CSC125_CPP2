#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word[10][10];
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            word[i][j]="null ";
        }
    }
    word[2][3]="Bryna";
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            cout << word[i][j];
        }
        cout << endl;
    }
    return 0;
}
