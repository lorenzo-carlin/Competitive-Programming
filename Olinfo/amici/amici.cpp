#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LOG = 30;
constexpr int MAXN = 1e6;
int up[MAXN][LOG];

int lift(int v, int k)
{
	int tmp = v;
	for(int j = LOG-1; j >= 0; j--)
	{
		if(k & (1 << j))
		{
			tmp = up[tmp][j];
		}
	}

	return tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, t; cin >> n >> k >> t;
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		a--;
		up[i][0] = a;
	}

	for(int j = 1; j < LOG; ++j)
	{
		for(int i = 0; i < n; ++i)
		{
			up[i][j] = up[up[i][j-1]][j-1];
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			cout << up[i][j] << " ";
		}
		cout << "\n";
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			cout << up[i][j] << " ";
		}
		cout << "\n";
	}

	vector<int> v(k);
	vector<bool> vis(n, false);
	for(int &i: v) cin >> i;
	for(int i = 0; i < k; ++i)
	{
		int res = lift(i, t);
		vis[res] = true;
	}

	for(int i = 0; i < n; ++i)
	{
		if(vis[i])
		{
			cout << i << "\n";
		}
	}

	for(int i = 0; i < n-1; ++i)
	{
		if(!vis[i] && vis[i+1])
		{
			cout << i+1 << "\n";
			return 0;
		}
	}

	if(!vis[n-1])
	{
		cout << 0 << "\n";
		return 0;
	}
}
