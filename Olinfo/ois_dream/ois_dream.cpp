#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 666013;

map<char,ll> mp =  {{'0', 0},{'1', 1},{'2', 2},{'3', 3},{'4', 4},{'5', 5},{'6', 6},{'7', 7},{'8', 8},{'9', 9}};

ll fast_exp(ll b, ll exp)
{
    if(exp == 1) return b;
    if(exp == 0) return 1;
    ll ans = fast_exp(b, exp/2);
    ans = (ans*ans) % mod;
    if(exp % 2) ans = (ans*b) % mod;
    return ans;
}

string add(string s)
{
    for(ll i = 0; i < s.size(); i++)
    {
        if(s[i] == '9')
        {
            s[i] = '0';
        } else
        {
            s[i]++;
            break;
        }
    }
    return s;
}

ll sttoi(string s)
{
    ll ans = 0;
    for(ll i = 0; i < s.size(); i++)
    {
        ans = (ans + (mp[s[s.size()-1-i]]*fast_exp(10, i)) % mod) % mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k, x; cin >> k >> x;
    ll sol = 0, tmp = 0;

    // PRIMA METà
    ll left = x/2;
    tmp = (k-1)*k/2*fast_exp(10, left);
    tmp %= mod;

    sol += tmp;
    sol %= mod;

    // SECONDA METà
    string s;
    if(x == 2) s = "0";
    else if(x == 4) s = "00";
    else if(x == 6) s = "000";
    else if(x == 8) s = "0000";
    else if(x == 10) s = "00000";
    else s = "000000";
    tmp = 0;
    for(ll i = 1; i < k; i++)
    {
        s = add(s);
        tmp += sttoi(s);
        tmp %= mod;
    }
    if(x > 10)
    {
        tmp *= fast_exp(10, left-6);
        tmp %= mod;
    }
    sol += tmp;
    sol %= mod;

    // TESTA E CODA
    tmp = k*((fast_exp(10, x-1)+1)%mod);
    tmp %= mod;

    sol += tmp;
    sol %= mod;

    cout << sol << "\n";
}