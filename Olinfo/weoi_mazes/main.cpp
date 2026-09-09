#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<char>> solve(ll k)
{
	vector<vector<char>> maze(200, vector<char> (200, '#'));
	maze[0][0] = '.';
	for(int i = 0; i < 200; ++i) maze[199][i] = '.';

	int anelli = 0;
	ll tmp = k;
	while(tmp > 1)
	{
		tmp /= 2;
		anelli++;
	}

	for(int i = 0; i < anelli; ++i)
	{
		maze[2*i][2*i] = maze[2*i+1][2*i] = maze[2*i+2][2*i] = '.';
		maze[2*i][2*i+1] = maze[2*i+2][2*i+1] = '.';
		maze[2*i][2*i+2] = maze[2*i+1][2*i+2] = maze[2*i+2][2*i+2] = '.';
	}

	for(int i = 0; i <= anelli; ++i)
	{
		if((1LL << i) & k)
		{
			for(int j = 2*i; j < 200; ++j) maze[j][2*i] = '.';
		}
	}

	return maze;
}
