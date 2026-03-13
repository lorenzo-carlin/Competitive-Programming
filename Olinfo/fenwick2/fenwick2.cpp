#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;

struct FenwickTree
{
	int n;
	vector<ll> bit;

	FenwickTree(int _n)
	{
		n = _n;
		bit.resize(n, 0);
	}

	void update(int ind, int delta)
	{
		while(ind < n)
		{
			bit[ind] += delta;
			bit[ind] %= mod;
			ind = (ind | (ind+1));
		}
	}

	ll query(int ind)
	{
		ll res = 0;
		while(ind >= 0)
		{
			res += bit[ind];
			res %= mod;
			ind = (ind & (ind+1))-1;
		}
		return res;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	vector<ll> v(n);
	vector<pair<int,int>> order(n);
	for(int i = n-1; i >= 0; i--)
	{
		cin >> v[i];
		order[i] = {v[i], i};
	}
	sort(rbegin(order), rend(order));

	FenwickTree fen = FenwickTree(n);

	ll sol = 0;
	for(int i = 0; i < n; ++i)
	{
		int val = order[i].first;
		int ind = order[i].second;

		ll tmp = fen.query(ind) + 1;
		tmp %= mod;
		fen.update(ind, tmp);

		sol += tmp;
		sol %= mod;
	}

	cout << sol << "\n";
}
