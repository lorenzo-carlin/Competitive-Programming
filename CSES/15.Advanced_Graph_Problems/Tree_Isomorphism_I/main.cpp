#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve()
{
	int n; cin >> n;
	vector<vector<int>> adj1(n), adj2(n);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj1[a].push_back(b);
		adj1[b].push_back(a);
	}
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj2[a].push_back(b);
		adj2[b].push_back(a);
	}
 
	map<vector<int>,int> hash;
	int tmr = 0;
 
	auto hashing = [&](vector<int> children) -> int
	{
		sort(begin(children), end(children));
		if(hash.count(children)) return hash[children];
		else return hash[children] = tmr++;
	};
 
	auto dfs = [&](auto dfs, int v, int p, vector<vector<int>> &adj) -> int
	{
		vector<int> children;
		for(int u: adj[v])
		{
			if(u == p) continue;
			children.push_back(dfs(dfs, u, v, adj));
		}
		return hashing(children);
	};
 
	int t1 = dfs(dfs, 0, -1, adj1);
	int t2 = dfs(dfs, 0, -1, adj2);
 
	if(t1 == t2) cout << "YES\n";
	else cout << "NO\n";
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t; cin >> t;
	while(t--) solve();
}
