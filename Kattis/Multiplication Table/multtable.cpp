#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m; cin >> n >> m;
    ll rad = sqrt(m);
    set<ll> s;
    for(int i = 1; i <= rad && i <= n; ++i)
    {
        if(m % i == 0 && m/i <= n)
        {
            s.insert(i);
            s.insert(m/i);
        }
    }
    cout << s.size() << "\n";
}