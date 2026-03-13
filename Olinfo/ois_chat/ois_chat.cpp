#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    map<string,int> mp;
    for(int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        mp[s] = i;
    }

    vector<pair<int,string>> sol;
    for(auto el: mp)
    {
        sol.push_back({el.second, el.first});
    }
    
    sort(sol.rbegin(), sol.rend());
    for(auto el: sol)
    {
        cout << el.second << "\n";
    }
}