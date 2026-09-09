#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int m1 = 1e9+7, m2 = 1e9+9;
constexpr int p1 = 29, p2 = 31;

struct Hash
{
	string s;
	int n;

	vector<ll> pow1, pow2, h1, h2;

	Hash() {}
	Hash(string _s)
	{
		s = _s;
		n = s.size();

		pow1.resize(n+1, 1);
		pow2.resize(n+1, 1);
		for(int i = 1; i <= n; ++i)
		{
			pow1[i] = (pow1[i-1] * p1) % m1;
			pow2[i] = (pow2[i-1] * p2) % m2;
		}

		h1.resize(n+1, 0);
		h2.resize(n+1, 0);
		for(int i = 1; i <= n; ++i)
		{
			h1[i] = (h1[i-1] * p1 + (s[i-1] - 'a' + 1)) % m1;
			h2[i] = (h2[i-1] * p2 + (s[i-1] - 'a' + 1)) % m2;
		}
	}

	pair<ll,ll> query(int l, int len)
	{
		ll ans1 = (h1[l+len] - (h1[l] * pow1[len]) % m1 + m1) % m1;
		ll ans2 = (h2[l+len] - (h2[l] * pow2[len]) % m2 + m2) % m2;
		return {ans1, ans2};
	}
};

string min_lexicographical_rotation(string s)
{
	string t = s + s;
	int n = s.size();
	Hash hash = Hash(t);

	int mn = 0;
	for(int i = 1; i < n; ++i)
	{
		int l = 0, r = n-1;
		int lcp = 0;
		while(l <= r)
		{
			int m = (l + r) / 2;
			pair<ll,ll> x = hash.query(i, m+1), y = hash.query(mn, m+1);
			if(x == y)
			{
				l = m+1;
				lcp = m+1;
			} else
			{
				r = m-1;
			}
		}

		if(lcp == n) continue;
		if(t[i+lcp] < t[mn+lcp]) mn = i;
	}

	return t.substr(mn, n);
}

int main()
{
	int n, m; cin >> n >> m;
	map<string,ll> mp;
	string s;
	for(int i = 0; i < n; ++i)
	{
		cin >> s;
		s = min_lexicographical_rotation(s);
		mp[s]++;
	}

	ll ans = 0;
	for(auto el: mp)
	{
		ans += (ll)(el.second*(el.second-1))/2;
	}

	cout << ans << "\n";
}
