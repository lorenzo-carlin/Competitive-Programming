#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;

    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    sort(v.begin(), v.end());

    ll sol = 1;
    bool cond = false;
    for(auto i: v)
    {
        if(sol < i)
        {
            cout << sol << "\n";
            cond = true;
            break;
        } else
        {
            sol += i;
        }
    }

    if(!cond)
    {
        cout << sol << "\n";
    }

}