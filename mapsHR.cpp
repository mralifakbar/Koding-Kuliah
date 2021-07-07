#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q, type, val;
    string name;
    cin >> Q;
    map <string, int> m;

    for(int i = 0; i < Q; i++)
    {
        cin >> type >> name;

        switch (type)
        {
        case 1:
            cin >> val;
            m[name] += val;
            break;
        
        case 2:
            m.erase(name);
            break;
        
        case 3:
            cout << m[name] << endl;
        }
    }
}