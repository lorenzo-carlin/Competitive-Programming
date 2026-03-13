#include <bits/stdc++.h>
#pragma GCC Optimize("Ofast")
using namespace std;
using ll = long long;

enum
{
	Left,
	Up,
	Right,
	Down
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	char mat[n][n];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}

	vector<vector<int>> v(n, vector<int>(n, 1e9));
	vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (n, vector<bool> (4, false)));
	queue<array<int,4>> q;
	v[0][0] = 0;
	vis[0][0][Left] = vis[0][0][Up] = true;
	// x cella, y cella, da dove arrivo, cambi direzione
	q.push({0, 1, Left, 0});
	q.push({1, 0, Up, 0});

	while(!q.empty())
	{
		int x = q.front()[0];
		int y = q.front()[1];
		int d = q.front()[2];
		int c = q.front()[3];
		q.pop();

		if(x < 0 || x >= n) continue;
		if(y < 0 || y >= n) continue;
		if(mat[x][y] == '#') continue;
		if(c > v[x][y]) continue;
		if(c == v[x][y] && vis[x][y][d]) continue;
		v[x][y] = c;
		if(c < v[x][y]) vis[x][y] = {false, false, false, false};
		vis[x][y][d] = true;
		
		if(d == Left)
		{
			q.push({x+1, y, Up, c+1});
			q.push({x, y+1, Left, c});
			q.push({x-1, y, Down, c+1});
		} else if(d == Up)
		{
			q.push({x+1, y, Up, c});
			q.push({x, y+1, Left, c+1});
			q.push({x, y-1, Right, c+1});
		} else if(d == Right)
		{
			q.push({x+1, y, Up, c+1});
			q.push({x-1, y, Down, c+1});
			q.push({x, y-1, Right, c});
		} else if(d == Down)
		{
			q.push({x, y+1, Left, c+1});
			q.push({x-1, y, Down, c});
			q.push({x, y-1, Right, c+1});
		}
	}

	cout << ((v[n-1][n-1] == 1e9) ? (-1) : (v[n-1][n-1])) << "\n";
}
