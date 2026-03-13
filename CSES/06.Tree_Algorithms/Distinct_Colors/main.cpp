#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> col, sol;

set<int> dfs(int n, int p)
{
	set<int> ans;
	ans.insert(col[n]);

	for(int v: adj[n])
	{
		if(p == v) continue;
		auto tmp = dfs(v, n);
		if(tmp.size() > ans.size())
		{
			swap(ans, tmp);
		}
		for(int el: tmp)
		{
			ans.insert(el);
		}
	}

	sol[n] = ans.size();
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	adj.resize(n);
	col.resize(n);
	sol.resize(n);
	for(int &i: col) cin >> i;
	for(int i = 0; i < n-1; ++i)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	auto tmp = dfs(0, -1);

	for(int i = 0; i < n; ++i)
	{
		cout << sol[i] << " ";
	}
	cout << "\n";
}
