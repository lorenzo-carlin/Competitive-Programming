#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
vector<vector<int>> adj;
vector<int> sol;
bool cond = true;

void dfs(int v, int p)
{
	// OK
	int children = 0;
	set<pair<int,int>> s;
	for(int u: adj[v])
	{
		if(u == p) continue;
		dfs(u, v);
		children++;
		s.insert({sol[u], u});
	}

	// OK
	if(children == 0) return;

	// OK
	if(children == 1)
	{
		auto it = s.begin();
		int u = (*it).second;
		sol[v] = sol[u]+1;
		return;
	}

	// OK
	if(children == 2)
	{
		if(p == -1)
		{
			auto it = s.begin();
			int a = (*it).second;
			it++;
			int b = (*it).second;
			sol[v] = sol[a]+sol[b]+2;
			if(sol[v] < k) cond = false;
		} else
		{
			auto it = s.lower_bound({k-1, -1});
			if(it != s.end())
			{
				auto it2 = s.begin();
				int a = (*it2).second;
				it2++;
				int b = (*it2).second;
				if((*it).second == a) sol[v] = sol[b]+1;
				else if((*it).second == b) sol[v] = sol[a]+1;
			} else
			{
				auto it = s.begin();
				int a = (*it).second;
				it++;
				int b = (*it).second;
				if(sol[a]+sol[b]+2 < k) cond = false;
				sol[v] = 0;
			}
		}
		return;
	}

	set<int> vis, notFound, accoppiati, extra;
	for(auto el: s)
	{
		if(vis.count(el.second)) continue;
		vis.insert(el.second); 
		if(el.first < k-1)
		{
			auto it = s.lower_bound({k-el.first-2, -1});
			while(it != s.end() && vis.count((*it).second)) it++;
			if(it == s.end())
			{
				notFound.insert(el.second);
			} else
			{
				vis.insert((*it).second);
				accoppiati.insert(el.second);
				accoppiati.insert((*it).second);
			}
		} else
		{
			extra.insert(el.second);
		}
	}
	if(notFound.size() > 1)
	{
		cond = false;
	} else if(notFound.size() == 1)
	{
		sol[v] = sol[*(notFound.begin())]+1;
	} else if(notFound.size() == 0 && extra.size())
	{
		auto it = extra.end();
		it--;
		sol[v] = sol[*it]+1;
	}


	// } else if(notFound.size() == 1)
	// {
	//  	sol[v] = sol[*(notFound.begin())]+1;
	// }
}

bool possible(int val)
{
	k = val;
	cond = true;
	sol.clear();
	sol.assign(n, 0);

	dfs(0, -1);
	if(sol[0] < k) cond = false;
	return cond;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	adj.resize(n);
	sol.resize(n);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int l = 0, r = n;
	while(l < r)
	{
		int m = (l + r) / 2;
		if(possible(m))
		{
			l = m+1;
		} else
		{
			r = m;
		}
	}

	if(possible(r)) cout << r << "\n";
	else cout << r-1 << "\n";

	// for(int el: sol) cout << el << " ";
	// cout << "\n";
}
