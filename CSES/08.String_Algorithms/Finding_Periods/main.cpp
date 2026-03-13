#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    int S = s.size();

    const ll p = 9973, m = 1e9+9;

    vector<ll> p_pow(S);
    p_pow[0] = 1;
    for(int i = 1; i < S; ++i)
        p_pow[i] = (p_pow[i-1] * p) % m;
    
    vector<ll> h(S+1, 0);
    for(int i = 0; i < S; ++i)
        h[i+1] = (h[i] + p_pow[i] * (s[i] - 'a' + 1)) % m;
    
    for(int i = 1; i < S; ++i)
    {
        bool cond = true;
        ll cur_h = h[i];
        int j;
        for(j = i; j+i < S; j+=i)
        {
            ll tmp = (h[j+i] + m - h[j]) % m;
            if((cur_h * p_pow[j] % m) != tmp)
            {
                cond = false;
                break;
            }
        }

        // analisi dell'ultimo periodo (parziale)
        ll tmp = (h[S] + m - h[j]) % m;
        cur_h = h[S-j];
        if((cur_h * p_pow[j] % m) != tmp) cond = false;

        if(cond) cout << i << " ";
    }
    cout << S << "\n";
}