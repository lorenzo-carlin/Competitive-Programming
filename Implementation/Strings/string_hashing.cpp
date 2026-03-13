#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct hash
{
	constexpr ll m = 2e9+11;
	constexpr ll p = 29;

	int n;
	string s;
	vector<ll> h, p_pow;

	Hash(int _n, string _s) : n(_n), s(_s)
	{
		h.resize(n+1);
		p_pow.resize(n+1);
		h[0] = 0;
		p_pow[0] = 1;

		for(int i = 1; i <= n; ++i)
		{
			p_pow[i] = p_pow[i-1] * p % mod;
			h[i] = (p * h[i-1] + (s[i-1] - '`') % m;
		}
	}

	ll get_hash(int l, int len)
	{
		return (h[l+len] - h[l] * p_pow[len] % m + m) % m;
	}

	bool same(int l, int r, int len)
	{
		return get_hash(l, len) == get_hash(r, len);
	}
};

int main()
{
    string s, t; cin >> s >> t;
    // s: pattern
    // t: text

    const int p = 9973;
    const int m = 1e9+9;

    vector<ll> p_pow(t.size());
    p_pow[0] = 1;
    for(int i = 1; i < p_pow.size(); ++i)
        p_pow[i] = (p_pow[i-1] * p) % m;
    
    vector<ll> h(t.size()+1, 0);
    for(int i = 0; i < t.size(); ++i)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    
    ll h_s = 0;
    for(int i = 0; i < s.size(); ++i)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    
    vector<int> occ;
    for(int i = 0; i + s.size() - 1 < t.size(); ++i)
    {
        ll cur_h = (h[i+s.size()] + m - h[i]) % m;
        if(cur_h == h_s * p_pow[i] % m)
            occ.push_back(i);
    }

    for(auto el: occ) cout << el << " ";
}
