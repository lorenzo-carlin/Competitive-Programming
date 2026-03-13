#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    for(int i = 1; i <= 5; ++i)
    {
        string p; cin >> p;
        for(int j = 0; j < p.size()-2; ++j)
        {
            if(p[j] == 'F' && p[j+1] == 'B' && p[j+2] == 'I')
            {
                s.insert(i);
                break;
            }
        }
    }
    if(s.size() == 0)
    {
        cout << "HE GOT AWAY!\n";
    } else
    {
        for(auto el: s)
        {
            cout << el << " ";
        }
        cout << "\n";
    }
}