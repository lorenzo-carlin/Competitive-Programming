#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct Hash
{
	int n;
	string s;
	ll m1 = 1e9+7, m2 = 1e9+9;
	ll p1 = 29, p2 = 37;
 
	vector<ll> p_pow1, p_pow2, h1, h2;
 
	Hash(string s) : s(s), n(s.size())
	{
		p_pow1.resize(n+1, 1);
		p_pow2.resize(n+1, 1);
		h1.resize(n+1, 0);
		h2.resize(n+1, 0);
		for(int i = 1; i <= n; ++i)
		{
			p_pow1[i] = (p_pow1[i-1]*p1) % m1;
			p_pow2[i] = (p_pow2[i-1]*p2) % m2;
		}
		for(int i = 1; i <= n; ++i)
		{
			h1[i] = (h1[i-1]*p1 + (s[i-1] - 'a' + 1)) % m1;
			h2[i] = (h2[i-1]*p2 + (s[i-1] - 'a' + 1)) % m2;
		}
	}
 
	pair<ll,ll> get_hash(int l, int len)
	{
		return {(h1[l+len] - (h1[l]*p_pow1[len] % m1) + m1) % m1, (h2[l+len] - (h2[l]*p_pow2[len] % m2) + m2) % m2};
	}
 
	bool same(int l, int r, int len)
	{
		return get_hash(l, len) == get_hash(r, len);
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	string s, p;
	cin >> s;
	cin >> p;
 
	string t = s+'$'+p;
	Hash l = Hash(t);
	int ans = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(l.same(i, s.size()+1, p.size()))
		{
			ans++;
		}
	}
 
	cout << ans << "\n";
}
