#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        map<int,int> mp;
        for(int i = 0; i < n; ++i)
        {
            int a; cin >> a;
            mp[a]++;
        }
        bool cond = true;
        for(int i = 0; i < 100; ++i)
        {
            if(mp[i] < mp[i+1])
            {
                cond = false;
                break;
            }
        }
        if(cond)
        {
            cout << "YES\n";
        } else
        {
            cout << "NO\n";
        }
    }
}
