#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll cnt = 0;
    for(int i = 0; i < 15; ++i)
    {
        ll c; cin >> c;
        cnt += c*v[i];
    }
    
    vector<ll> sol(15, 0);
    for(int i = 14; i >= 0; --i)
    {
        sol[i] = cnt/v[i];
        cnt = cnt%v[i];
    }

    for(ll i:sol) cout << i << " ";
}