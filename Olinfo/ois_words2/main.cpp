#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 100000;
const ll mod = 1e9+7;
ll pot_26[MAX];

void precalculate()
{
    pot_26[0] = 1;
    for(int i = 1; i < MAX; ++i)
    {
        pot_26[i] = (pot_26[i-1] * 26) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precalculate();

    string s; cin >> s;
    ll sz = s.size();
    ll sol = -1;

    for(int i = 0; i < sz; ++i)
    {
        sol = ((sol % mod) + ((s[i] - 'a' + 1) * pot_26[sz-(i+1)]) % mod) % mod;
    }

    cout << sol << "\n";
}