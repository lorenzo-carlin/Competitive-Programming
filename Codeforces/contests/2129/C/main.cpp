#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2005;

void solve()
{
	int n; cin >> n;
	vector<vector<int>> adj(MAXN);
	vector<bool> vis(MAXN, false);
	map<pair<int,int>,int> idx; // indici degli archi
	vector<bool> ciclo(n, 0); // ciclo di ogni arco
	vector<bool> archi(n, true);
	int cnt = 0;
	for(int i = 0, a, b; i < n; ++i)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		idx[{a, b}] = cnt++;
		for(int j = a; j <= b; j++) vis[j] = true;
	}

	int f = 0;
	for(int i = 0; i < MAXN; ++i) if(vis[i]) f++;

	vector<int> col(MAXN, 0);
	int nr_ciclo = 0;
	stack<int> s;
	auto dfs = [&] (auto dfs, int v, int p) -> void
	{
		col[v] = 1;
		s.push(v);
		for(int u: adj[v])
		{
			if(u == p) continue;
			if(col[u] == 2) continue;
			if(col[u] == 1) // ciclo, targhetto i nomi
			{
				nr_ciclo++;
				stack<int> prov;
				while(s.top() != u)
				{
					prov.push(s.top());
					int fr = s.top();
					s.pop();
					int sn = s.top();
					ciclo[idx[{min(fr,sn), max(fr,sn)}]] = nr_ciclo;
				}
				while(!prov.empty())
				{
					s.push(prov.top());
					prov.pop();
				}
			} else
			{
				dfs(dfs, u, v);
			}
		}
		col[v] = 2;
		s.pop();
	};
	for(int i = 0; i < MAXN; ++i)
	{
		if(col[i] == 0)
		{
			dfs(dfs, i, -1);
		}
	}

	vector<bool> cicli_rimossi(nr_ciclo, false);
	for(int i = 0; i < n; ++i)
	{
		if(ciclo[i] == 0) continue;
		if(cicli_rimossi[ciclo[i]]) continue;
		cicli_rimossi[ciclo[i]] = true;
		archi[i] = false;
	}

	vector<int> ans;
	for(int i = 0; i < n; ++i)
	{
		if(archi[i]) ans.push_back(i+1);
	}
	cout << ans.size() << "\n";
	for(auto el: ans) cout << el << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
