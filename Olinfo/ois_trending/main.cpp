#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t; cin >> n >> t;
    int q = n - t;
    map<string,int> mp;
    map<int,set<string>> mp_rev;
    deque<string> d;
    string s;
    for(int i = 0; i < t; ++i)
    {
        cin >> s;
        mp[s]++;
        d.push_back(s);
    }
    for(auto el: mp)
    {
        mp_rev[el.second].insert(el.first);
    }
    int mx = (*mp.begin()).second;
    cout << *(mp_rev[mx].begin()) << "\n";

    for(int i = 0; i < q; ++i)
    {
        cin >> s;
        d.push_back(s);
        if(mp[s] != 0)
        {
            mp_rev[mp[s]].erase(s);
        }
        mp[s]++;
        mp_rev[mp[s]].insert(s);
        mp_rev[mp[d.front()]].erase(d.front());
        mp[d.front()]--;
        mp_rev[mp[d.front()]].insert(d.front());
        d.pop_front();
        int mx = (*mp.begin()).second;
        cout << *(mp_rev[mx].begin()) << "\n";
    }

    
}