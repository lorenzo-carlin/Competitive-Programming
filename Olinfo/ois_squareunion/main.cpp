#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> x(n), r(n);
	for(int &i: x) cin >> i;
	for(int &i: r) cin >> i;

	map<int,vector<int>> mp;
	vector<bool> vis(n, false);
	for(int i = 0; i < n; ++i)
	{
		mp[x[i]-r[i]].push_back(i);
		mp[x[i]+r[i]].push_back(i);
	}

	ll sol = 0, last = 0;
	priority_queue<pair<int,int>> pq;
	for(auto el: mp)
	{
		// elaboro
		int p = el.first;
		int mx = 0;
		while(!pq.empty() && !vis[pq.top().second])
		{
			pq.pop();
		}
		if(!pq.empty())
		{
			mx = pq.top().first;
		}
		sol += (ll)(p-last)*mx;
		last = p;

		// apro e chiudo
		for(int i: el.second)
		{
			if(!vis[i])
			{
				pq.push({r[i], i});
				vis[i] = true;
			} else
			{
				vis[i] = false;
			}
		}
	}

	cout << 2*sol << "\n";
}
