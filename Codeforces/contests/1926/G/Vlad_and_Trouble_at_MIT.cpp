#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<array<int,3>> dp;
string s;

int dfs(int node, char type)
{
	int ind;
	if(type == 'S') ind = 0;
	if(type == 'P') ind = 1;
	if(type == 'C') ind = 2;

	if(dp[node][ind] != -1) return dp[node][ind];

	int ans = 0;

	if(ind == 0)
	{
		for(int v: adj[node])
		{
			dfs(v, s[v]);
			if(s[v] == 'S') ans += dp[v][0];
			else if(s[v] == 'P') ans += (dp[v][1]+1);
			else if(s[v] == 'C') ans += (min(dp[v][0], dp[v][1]+1));
		}
	} else if(ind == 1)
	{
		for(int v: adj[node])
		{
			dfs(v, s[v]);
			if(s[v] == 'S') ans += (dp[v][0]+1);
			else if(s[v] == 'P') ans += dp[v][1];
			else if(s[v] == 'C') ans += (min(dp[v][0]+1, dp[v][1]));
		}
	} else
	{
		dfs(node, 'S');
		dfs(node, 'P');
		ans = min(dp[node][0], dp[node][1]);
	}

	return dp[node][ind] = ans;
}

void solve()
{
	adj.clear();
	dp.clear();
	s.clear();

	int n; cin >> n;
	adj.resize(n);
	for(int i = 1; i < n; ++i)
	{
		int num; cin >> num;
		adj[num-1].push_back(i);
	}
	cin >> s;

	// [i][0] = 'S', [i][1] = 'P', [i][2] = 'C'
	dp.resize(n, array<int,3>{-1, -1, -1});

	dfs(0, s[0]);
	
	if(s[0] == 'S') cout << dp[0][0] << "\n";
	else if(s[0] == 'P') cout << dp[0][1] << "\n";
	else cout << dp[0][2] << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}

