#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;

    unordered_set<ll> s;

    for(ll i = 2; i*i <= n; i++)
    {
        ll curr = i*i;
        while(curr <= n)
        {
            s.insert(curr);
            curr *= i;
        }
    }

    cout << n-s.size() << "\n";
}
