#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct myds
{
	int sum = 1;
	int mx = 0;
	multiset<int> s;

	myds() {}

	void insert(int v)
	{
		s.insert(v);
		if(v > mx)
		{
			sum += mx;
			mx = v;
		} else
		{
			sum += v;
		}
	}

	void erase(int v)
	{
		s.erase(s.find(v));
		if(mx == v)
		{
			if(s.empty())
			{
				mx = 0;
			} else
			{
				auto it = s.end();
				it--;
				mx = *it;
			}
			sum -= mx;
		} else
		{
			sum -= v;
		}
	}

	int get_sum()
	{
		return sum;
	}
};

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

	vector<myds> dp(n);
	auto dfs = [&](auto dfs, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			dfs(dfs, u, v);
			dp[v].insert(dp[u].get_sum());
		}
	};

	vector<int> ans(n);

	dfs(dfs, 0, -1);
	ans[0] = dp[0].get_sum();
	
	auto rerooting = [&](auto rerooting, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			// sposto la root a u
			dp[v].erase(dp[u].get_sum());
			dp[u].insert(dp[v].get_sum());
			ans[u] = dp[u].get_sum();
			// ricorsiva
			rerooting(rerooting, u, v);
			// sposto la root a v
			dp[u].erase(dp[v].get_sum());
			dp[v].insert(dp[u].get_sum());
		}
	};

	rerooting(rerooting, 0, -1);

	for(int el: ans) cout << el << " ";
	cout << "\n";
}
