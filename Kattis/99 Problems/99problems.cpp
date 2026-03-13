#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    map<int,int> mp;
    multiset<int> s;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        s.insert(a);
        mp[a]++;
    }
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        if(a == 1)
        {
            auto it = s.upper_bound(b);
            if(it == s.end())
            {
                cout << "-1\n";
            } else
            {
                cout << *it << "\n";
                mp[*it]--;
                if(mp[*it] == 0)
                {
                    s.erase(*it);
                }
            }
        } else if(a == 2)
        {
            auto it = s.upper_bound(b);
            if(it == s.begin())
            {
                cout << "-1\n";
            } else
            {
                it--;
                cout << *it << "\n";
                mp[*it]--;
                if(mp[*it] == 0)
                {
                    s.erase(*it);
                }
            }
            
        }
    }
}