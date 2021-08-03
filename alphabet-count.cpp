#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    vector <char> inputStr;
    int countLen = 1;

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
            inputStr.push_back(ch);
        }

        countLen++;
    }

    vector <int> position;
    
    for(int i = 'a'; i <= 'z'; i++)
    {
        int count = 0, index = 0;
        for(char _ch: inputStr)
        {
            if(_ch == i)
            {
                count++;
                position.push_back(index);
            }
            index++;
        }

        if(count != 0)
        {
            cout << char(i) << ": " << count << " kali pada ";
            for(int _index: position)
            {
                cout << _index << ", ";
            }
            cout << '\n';
        }

        position.clear();
    }
}