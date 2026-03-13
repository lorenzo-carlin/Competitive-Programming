#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct myds
{
	int freq_mx = 0;
	int nr_freq_mx = 0;
	map<int,int> mp;

	myds() {}
	myds(int val)
	{
		mp[val]++;
		freq_mx = 1;
		nr_freq_mx = 1;
	}
};

myds merge(myds a, myds b)
{
	if(a.mp.size() > b.mp.size()) swap(a, b);

	for(auto el: a.mp)
	{
		b.mp[el.first] += el.second;
		if(b.mp[el.first] > b.freq_mx)
		{
			b.freq_mx = b.mp[el.first];
			b.nr_freq_mx = 1;
		} else if(b.mp[el.first] == b.freq_mx)
		{
			b.nr_freq_mx++;
		}
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> c(n);
	for(int &i: c) cin >> i;
	vector<vector<int>> adj(n);
	for(int i = 1, a; i < n; ++i)
	{
		cin >> a;
		adj[i].push_back(a);
		adj[a].push_back(i);
	}

	int ans = 0;
	auto dfs = [&] (auto dfs, int v, int p) -> myds
	{
		myds tmp = myds(c[v]);
		for(int u: adj[v])
		{
			if(u == p) continue;
			tmp = merge(tmp, dfs(dfs, u, v));
		}
		ans = max(ans, tmp.nr_freq_mx);
		return tmp;
	};

	dfs(dfs, 0, -1);

	cout << ans << "\n";
}
