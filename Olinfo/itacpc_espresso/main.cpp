#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    map<string,int> mp;
    mp["espresso"] = 1;
    mp["espresso-doppio"] = 2;
    mp["cappuccino"] = 1;
    mp["affogato"] = 2;
    mp["dead-eye"] = 3;
    mp["irish-coffee"] = 2;

    int n; cin >> n;
    int tot = 0;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        tot += mp[s];
    }

    cout << (tot+1) / 2 << "\n";
}
