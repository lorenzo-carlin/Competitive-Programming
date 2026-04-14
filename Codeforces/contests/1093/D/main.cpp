#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244353;

void solve()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> col(n, 0);
	vector<int> dep(n, -1);
	bool impossible = false;

	// {ans_se_pari, ans_se_dispari}
	auto dfs = [&] (auto dfs, int v, int p) -> pair<ll,ll>
	{
		col[v] = 1;
		ll pari = 1, dispari = 2;

		for(int u: adj[v])
		{
			if(u == p) continue;
			if(col[u] == 1 && (dep[v] - dep[u]) % 2 == 0)
			{
				impossible = true;
			}
			if(dep[u] == -1)
			{
				dep[u] = dep[v]+1;
				pair<ll,ll> tmp = dfs(dfs, u, v);
				pari *= tmp.second;
				pari %= mod;
				dispari *= tmp.first;
				dispari %= mod;
			}
		}

		col[v] = 2;
		return {pari, dispari};
	};

	ll tot = 1;

	for(int i = 0; i < n; ++i)
	{
		if(col[i] == 0)
		{
			dep[i] = 0;
			pair<ll,ll> cur = dfs(dfs, i, -1);
			tot *= (cur.first + cur.second);
			tot %= mod;
		}
	}

	if(impossible) cout << 0 << "\n";
	else cout << tot << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
