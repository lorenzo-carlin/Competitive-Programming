#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	char mat[n][m];
	bool vis[n][m];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	auto bfs = [&] (auto bfs, int x, int y) -> void
	{
		if(vis[x][y]) return;
		vis[x][y] = true;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{



