#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int GCD(int a, int b)
{
	if(b == 0) return a;
	else return GCD(b, a%b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		v[i]--;
	}

	vector<bool> vis(n, false);
	vector<int> is;
	int tot = 0;
	for(int i = 0; i < n; ++i)
	{
		if(vis[i]) continue;
		int ind = i;
		vector<int> cycle;
		while(!vis[ind])
		{
			vis[ind] = true;
			cycle.push_back(ind);
			ind = v[ind];
		}
		tot += (cycle.size()-1);
		sort(begin(cycle), end(cycle));
		if(cycle.size() < 2) continue;
		int g = cycle[1]-cycle[0];
		for(int j = 1; j < cycle.size()-1; ++j)
		{
			g = GCD(g, cycle[j+1]-cycle[j]);
		}
		is.push_back(g);
	}

	vector<int> ans(n, -1);
	if(is.empty())
	{
		ans.assign(n, 0);
	} else
	{
		int g = is[0];
		for(int i = 1; i < is.size(); ++i)
			g = GCD(g, is[i]);
		for(int i = 0; i < n; ++i)
			if(g % (i+1) == 0)
				ans[i] = tot;
	}

	for(int el: ans) cout << el << " ";
	cout << "\n";
}
