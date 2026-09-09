#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	vector<vector<int>> adj(n);
	vector<int> out(n, 0);
	for(int i = 0; i < n*(n-1)/2; ++i)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		out[a]++;
	}

	int mx = 0, mx_ind = -1;
	for(int i = 0; i < n; ++i)
	{
		if(out[i] > mx)
		{
			mx = out[i];
			mx_ind = i;
		}
	}

	int st = mx_ind;
	stack<int> s;
	vector<bool> vis(n, false);
	bool solved = false;

	auto dfs = [&] (auto self, int node) -> void
	{
		s.push(node);
		vis[node] = true;

		if(s.size() == n)
		{
			solved = true;
			return;
		}

		for(int u: adj[node])
		{
			if(solved) return;
			if(!vis[u])
			{
				self(self, u);
			}
		}

		if(solved) return;
		s.pop();
		vis[node] = false;
	};

	dfs(dfs, st);

	vector<pair<int,int>> sol(n-1);
	sol[0].second = s.top();
	s.pop();

	int ind = 1;
	while(s.size() > 1)
	{
		sol[ind-1].first = s.top();
		sol[ind].second = s.top();
		ind++;
		s.pop();
	}
	sol[ind-1].first = st;

	reverse(begin(sol), end(sol));
	cout << sol.size() << "\n";
	for(auto el: sol)
	{
		cout << el.first+1 << " " << el.second+1 << "\n";
	}
}
