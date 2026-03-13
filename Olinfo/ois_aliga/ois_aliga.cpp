#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LOG = 20;
constexpr int K = 11;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ll ans = 0;

	auto dfs = [&] (auto dfs, int v, int p, int d, int t) -> map<ll,int>
	{
		map<ll,int> mp;
		mp[d-t*v]++;

		for(int u: adj[v])
		{
			if(u == p) continue;
			map<ll,int> tmp = dfs(dfs, u, v, d+1, t);
			if(tmp.size() > mp.size()) swap(tmp, mp);
			for(auto el: tmp)
			{
				if(mp.count(2*d-el.first))
				{
					ans += el.second*mp[2*d-el.first];
				}
			}
			for(auto el: tmp)
			{
				mp[el.first] += el.second;
			}
		}

		return mp;
	};

	for(int i = 0; i < K; ++i)
	{
		dfs(dfs, 0, -1, 0, i);
	}

	vector<int> euler, depth, first_app(n);
	int tmr = 0;
	auto path = [&] (auto path, int v, int p, int d) -> void
	{
		euler.push_back(v);
		depth.push_back(d);
		first_app[v] = tmr;
		tmr++;

		for(int u: adj[v])
		{
			if(u == p) continue;
			path(path, u, v, d+1);
			euler.push_back(v);
			depth.push_back(d);
			tmr++;
		}

		euler.push_back(v);
		depth.push_back(d);
		tmr++;
	};

	path(path, 0, -1, 0);

	int sz = euler.size();

	vector<vector<int>> sparse_table(LOG, vector<int> (sz));
	for(int i = 0; i < sz; ++i) sparse_table[0][i] = depth[i];
	for(int j = 1; j < LOG; ++j)
	{
		for(int i = 0; i + (1 << j) < sz; ++i)
		{
			sparse_table[j][i] = min(sparse_table[j-1][i], sparse_table[j-1][i+(1<<(j-1))]);
		}
	}

	for(int i = 0; i < n/K; ++i)
	{
		for(int j = i+1; j < n/K; ++j)
		{
			int l = first_app[i], r = first_app[j];
			if(r < l) swap(l, r);
			int tmp = log2(r-l+1);
			int mn = min(sparse_table[tmp][l], sparse_table[tmp][r-(1 << tmp)+1]);
			int a = depth[l]+depth[r]-2*mn;
			if(a % (i+j) == 0 && (a/(i+j)) >= K && (a/(i+j)) < n) ans++;
		}
	}

	cout << ans << "\n";
}
