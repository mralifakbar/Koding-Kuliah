#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q, y, x;
    cin >> Q;
    set <int> s;
    set <int>::iterator it;
    for(int i = 0; i < Q; i++)
    {
        cin >> y >> x;

        switch (y)
        {
        case 1:
            s.insert(x);
            break;
        
        case 2:
            s.erase(x);
            break;
        
        case 3:
        {
            it = s.find(x);
            if(it == s.end())
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
        }
    }
}