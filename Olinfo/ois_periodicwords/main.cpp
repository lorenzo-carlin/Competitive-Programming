#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Hash
{
    const ll m = 1e9+9;
    const ll p = 29;

    int n;
    string s;
    vector<ll> hash;
    vector<ll> p_pow;

    Hash(int _n, string _s)
    {
        n = _n; s = _s;

        hash.resize(n+1); p_pow.resize(n+1);
        hash[0] = 0; p_pow[0] = 1;

        for(int i = 1; i <= n; ++i)
        {
            p_pow[i] = p_pow[i-1] * p % m;
            hash[i] = (p * hash[i-1] + (s[i-1] - 'a' + 1)) % m;
        }
    }

    ll getHash(int l, int len) { return(hash[l+len] + m - hash[l] * p_pow[len] % m) % m; }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    Hash hs(n, s);

    vector<vector<int>> divs(n+1);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 2*i; j <= n; j += i)
        {
            divs[j].push_back(i);
        }
        reverse(divs[i].begin(), divs[i].end());
    }

    int q; cin >> q;
    while(q--)
    {
        int l, r; cin >> l >> r;

        int sz = r - l + 1;
        bool sol = false;

        for(auto len: divs[sz])
        {
            if(hs.getHash(l, sz-len) == hs.getHash(l+len, sz-len))
            {
                sol = true;
                break;
            }
        }

        if(sol) cout << "YES\n";
        else cout << "NO\n";
    }
}