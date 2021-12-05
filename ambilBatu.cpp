#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    array <char, 100> inputStr;
    int countLen = 1, index = 0;

    while(cin.get(ch))
    {
        if(ch == '\n')
        {
            break;
        }
        else if(countLen == 1 && ch == '.')
        {
            cout << "Masukan tidak boleh diawali karakter '.' (titik)\n";
            exit(1);
        }
        else if (countLen > 100)
        {
            cout << "Masukan melebihi 100 karakter\n";
            exit(1);
        }
        else if(ch != ' ' && ch != '.')
        {
            inputStr[index] = tolower(ch);
            index++;
        }

        countLen++;
    }

    for(char _ch: inputStr)
    {
        cout << _ch;
    }
    // for(int i = 97; i < 123; i++)
    // {
    //     int count = 0, index = 0;
    //     array <int, 100> position;
    //     for(char _ch: inputStr)
    //     {
    //         if(_ch == i)
    //         {
    //             count++;
    //             position.fill(index);
    //         }
    //         index++;
    //     }

    //     if(count != 0)
    //     {
    //         cout << char(i) << ": " << count << " kali pada ";
    //         for(int _position: position)
    //         {
    //             cout << _position << ", ";
    //         }
    //     }
    // }
}