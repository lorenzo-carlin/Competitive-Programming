#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 205;
vector<int> adj[205];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	map<string,int> id;
	id["polycarp"] = 0;
	int cnt = 1;

	while(n--)
	{
		string a, b, c; cin >> a >> b >> c;
		for(int i = 0; i < a.size(); ++i) a[i] = tolower(a[i]);
		for(int i = 0; i < c.size(); ++i) c[i] = tolower(c[i]);
		if(!id.count(c)) id[c] = cnt++;
		if(!id.count(a)) id[a] = cnt++;
		adj[id[c]].push_back(id[a]);
	}

	int mx_dep = 0;
	auto dfs = [&] (auto dfs, int v, int p, int dep) -> void
	{
		mx_dep = max(mx_dep, dep);
		for(int u: adj[v])
		{
			if(u == p) continue;
			dfs(dfs, u, v, dep+1);
		}
	};
	dfs(dfs, 0, -1, 1);

	cout << mx_dep << "\n";
}

