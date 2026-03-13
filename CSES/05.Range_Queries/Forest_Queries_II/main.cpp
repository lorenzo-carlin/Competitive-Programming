#include <bits/stdc++.h>
using namespace std;

struct FenwickTree2D
{
	vector<vector<int>> bit;
	int n, m;

	FenwickTree2D(int _n, int _m)
	{
		n = _n;
		m = _m;
		bit.resize(n, vector<int> (m, 0));
	}

	FenwickTree2D(vector<vector<int>> &a) : FenwickTree2D(a.size(), a[0].size())
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				add(i, j, a[i][j]);
			}
		}
	}

	void add(int x, int y, int delta)
	{
		for(int i = x; i < n; i = (i | (i+1)))
		{
			for(int j = y; j < m; j = (j | (j+1)))
			{
				bit[i][j] += delta;
			}
		}
	}

	int sum(int x, int y)
	{
		int res = 0;
		for(int i = x; i >= 0; i = (i & (i+1))-1)
		{
			for(int j = y; j >= 0; j = (j & (j+1))-1)
			{
				res += bit[i][j];
			}
		}
		return res;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q; cin >> n >> q;
	char c;
	vector<vector<int>> a(n, vector<int>(n, 0));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> c;
			if(c == '*')
			{
				a[i][j]++;
			}
		}
	}
	
	FenwickTree2D fen = FenwickTree2D(a);

	for(int i = 0; i < q; ++i)
	{
		int type; cin >> type;
		if(type == 1)
		{
			int y, x; cin >> x >> y;
			x--; y--;
			if(a[x][y] == 0)
			{
				a[x][y] = 1;
				fen.add(x, y,  1);
			} else
			{
				a[x][y] = 0;
				fen.add(x, y, -1);
			}
		} else
		{
			int y1, x1, y2, x2; cin >> x1 >> y1 >> x2 >> y2;
			y1--; x1--; y2--; x2--;
			int ans = fen.sum(x2, y2);
			if(x1 != 0) ans -= fen.sum(x1-1, y2);
			if(y1 != 0) ans -= fen.sum(x2, y1-1);
			if(x1 != 0 && y1 != 0) ans += fen.sum(x1-1, y1-1);
			cout << ans << "\n";
		}
	}

}			
