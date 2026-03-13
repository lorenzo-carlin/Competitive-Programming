#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int,int>> t;

	int n; cin >> n;
	char c;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> c;
			if(c == 'T')
			{
				t.push_back({i+1, j+1});
			}
		}
	}

	int nr = t.size(), ans = 0;
	vector<bool> vis(nr, false);
	vector<int> dist(nr, 1e9);
	vis[0] = true;

	int mn = 1e9, mn_ind = -1;
	for(int i = 1; i < nr; ++i)
	{
		dist[i] = (t[i].f-t[0].f)*(t[i].f-t[0].f)+(t[i].s-t[0].s)*(t[i].s-t[0].s);
		if(dist[i] < mn)
		{
			mn = dist[i];
			mn_ind = i;
		}
	}

	int ind = mn_ind;

	for(int i = 1; i < nr; ++i)
	{
		vis[ind] = true;
		ans += mn;
		mn = 1e9, mn_ind = -1;

		for(int j = 0; j < nr; ++j)
		{
			if(vis[j]) continue;

			dist[j] = min(dist[j], (t[ind].f-t[j].f)*(t[ind].f-t[j].f)+(t[ind].s-t[j].s)*(t[ind].s-t[j].s));
			if(dist[j] < mn)
			{
				mn = dist[j];
				mn_ind = j;
			}
		}

		ind = mn_ind;
	}

	cout << ans << "\n";
}	

