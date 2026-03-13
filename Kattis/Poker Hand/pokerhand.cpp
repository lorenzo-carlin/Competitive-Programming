#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char,int> mp;
    for(int i = 0; i < 5; ++i)
    {
        string s; cin >> s;
        mp[s[0]]++;
    }
    int mx = 0;
    for(auto el: mp) mx = max(mx, el.second);
    cout << mx << "\n";
}