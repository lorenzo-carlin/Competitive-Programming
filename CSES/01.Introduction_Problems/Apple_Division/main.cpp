#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    ll a, sum = 0;
    set<ll> sol; sol.insert(0);
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        sum += a;
        set<ll> tmp;
        for(auto el: sol)
        {
            tmp.insert(el + a);
        }
        for(auto el: tmp)
        {
            sol.insert(el);
        }
    }
    ll mn = 1e18;
    for(auto el: sol)
    {
        ll dif = sum - el;
        mn = min(mn, abs(el - dif));
    }
    cout << mn << "\n";
}