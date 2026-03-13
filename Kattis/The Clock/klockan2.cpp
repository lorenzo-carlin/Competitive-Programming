#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    for(int i = 0; i < 12; ++i)
    {
        for(int j = 0; j < 60; ++j)
        {
            int h = 300*i + 5*j;
            int m = j * 60;
            int sol = (m > h) ? (m - h) : (m - h + 3600);
            if(sol == n)
            {
                string sh = to_string(i);
                if(sh.size() == 1) sh.insert(sh.begin(), '0');
                string sm = to_string(j);
                if(sm.size() == 1) sm.insert(sm.begin(), '0');
                cout << sh << ":" << sm << "\n";
            }
        }
    }
}