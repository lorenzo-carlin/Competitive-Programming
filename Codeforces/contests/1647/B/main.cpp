#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, m; cin >> n >> m;
	bool mat[n][m];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			char c; cin >> c;
			if(c == '0') mat[i][j] = false;
			else mat[i][j] = true;
		}
	}

	bool vis[n][m];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			vis[i][j] = false;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(mat[i][j] && !vis[i][j])
			{
				int cnt = 0, mn_x = 1e9, mn_y = 1e9, mx_x = -1, mx_y = -1;
				queue<array<int,2>> q;
				q.push({i, j});
				while(!q.empty())
				{
					auto co = q.front();
					q.pop();

					if(co[0] < 0 || co[0] >= n || co[1] < 0 || co[1] >= m) continue;
					if(!mat[co[0]][co[1]]) continue;
					if(vis[co[0]][co[1]]) continue;

					cnt++;
					vis[co[0]][co[1]] = true;
					mn_x = min(mn_x, co[0]);
					mx_x = max(mx_x, co[0]);
					mn_y = min(mn_y, co[1]);
					mx_y = max(mx_y, co[1]);

					q.push({co[0]-1, co[1]});
					q.push({co[0], co[1]+1});
					q.push({co[0]+1, co[1]});
					q.push({co[0], co[1]-1});
				}

				int exp = (mx_y-mn_y+1)*(mx_x-mn_x+1);
				
				if(exp != cnt)
				{
					cout << "NO\n";
					return;
				}
			}
		}
	}

	cout << "YES\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
