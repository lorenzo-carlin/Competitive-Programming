#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m; cin >> n >> m;
    map<char,int> mp;
    string s; cin >> s;
    for(char i: s)
    {
        mp[i]++;
    }

    int ans = 0;
    ans += max(0, m-mp['A']);
    ans += max(0, m-mp['B']);
    ans += max(0, m-mp['C']);
    ans += max(0, m-mp['D']);
    ans += max(0, m-mp['E']);
    ans += max(0, m-mp['F']);
    ans += max(0, m-mp['G']);

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}