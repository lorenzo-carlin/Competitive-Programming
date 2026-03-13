#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int col = 53;
constexpr int rig = 7;
int mat[rig][col];

int main()
{
	int d, n; cin >> d >> n;
	int a;
	while(n--)
	{
		cin >> a;
		a--;
		mat[a%rig][a/rig]++;
	}

	for(int i = 0; i < rig; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(7*j + i >= d) continue;
			if(mat[i][j] < 10) cout << '.';
			else if(mat[i][j] < 20) cout << 'o';
			else cout << 'O';
		}
		cout << "\n";
	}
}
