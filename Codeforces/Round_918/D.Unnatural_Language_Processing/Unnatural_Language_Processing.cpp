#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<int,int> mp;

void solve()
{
    int sz; cin >> sz;
    string s; cin >> s;

    reverse(begin(s), end(s));
    string sol, tmp;
    for(int i = 0; i < sz-1; ++i)
    {
        if(mp[s[i]] == mp[s[i+1]] || tmp.size() == 2 || (mp[s[i]] == 'C' && tmp.size()))
        {
            tmp += s[i];
            sol += tmp;
            sol += ".";
            tmp.clear();
        } else
        {
            tmp += s[i];
        }
    }
    tmp += s.back();
    sol += tmp;

    reverse(begin(sol), end(sol));
    cout << sol << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mp['a'] = mp['e'] = 'V';
    mp['b'] = mp['c'] = mp['d'] = 'C';

    int t; cin >> t;
    while(t--) solve();
}
