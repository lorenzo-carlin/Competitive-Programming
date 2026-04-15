#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int n; cin >> n;
	array<int,2> a, b, c;
	cin >> a[0] >> a[1]; a[0]--; a[1]--;
	cin >> b[0] >> b[1]; b[0]--; b[1]--;
	cin >> c[0] >> c[1]; c[0]--; c[1]--;

	bool mat[n][n];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			mat[i][j] = false;
		}
	}

	// stessa riga
	for(int i = 0; i < n; ++i) mat[a[0]][i] = true;
	// stessa colonna
	for(int i = 0; i < n; ++i) mat[i][a[1]] = true;
	// alto dx
	int x = a[0], y = a[1];
	while(x >= 0 && y < n)
	{
		mat[x][y] = true;
		x--;
		y++;
	}
	// basso dx
	x = a[0], y = a[1];
	while(x < n && y < n)
	{
		mat[x][y] = true;
		x++;
		y++;
	}
	// basso sx
	x = a[0], y = a[1];
	while(x < n && y >= 0)
	{
		mat[x][y] = true;
		x++;
		y--;
	}
	// alto sx
	x = a[0], y = a[1];
	while(x >= 0 && y >= 0)
	{
		mat[x][y] = true;
		x--;
		y--;
	}

	bool vis[n][n];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			vis[i][j] = false;
		}
	}
	queue<array<int,2>> q;
	q.push(b);
	while(!q.empty())
	{
		auto co = q.front();
		q.pop();

		if(co[0] < 0 || co[0] >= n || co[1] < 0 || co[1] >= n) continue;

		if(mat[co[0]][co[1]] || vis[co[0]][co[1]]) continue;
		vis[co[0]][co[1]] = true;

		q.push({co[0]-1, co[1]});
		q.push({co[0]-1, co[1]+1});
		q.push({co[0], co[1]+1});
		q.push({co[0]+1, co[1]+1});
		q.push({co[0]+1, co[1]});
		q.push({co[0]+1, co[1]-1});
		q.push({co[0], co[1]-1});
		q.push({co[0]-1, co[1]-1});
	}

	if(vis[c[0]][c[1]]) cout << "YES\n";
	else cout << "NO\n";
}		
