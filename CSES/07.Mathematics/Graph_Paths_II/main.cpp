#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print(vector<vector<ll>> a)
{
	for(int i = 0; i < a.size(); ++i)
	{
		for(int j = 0; j < a.size(); ++j)
		{
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k; cin >> n >> m >> k;

	vector<vector<ll>> adj(n, vector<ll> (n, 0));
	for(int i = 0, a, b, c; i < m; ++i)
	{
		cin >> a >> b >> c;
		a--; b--;
		adj[a][b] = c;
	}

	auto multiplication = [&] (vector<vector<ll>> a, vector<vector<ll>> b) -> vector<vector<ll>>
	{
		vector<vector<ll>> ans(n, vector<ll> (n, 0));
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				for(int k = 0; k < n; ++k)
				{
					ans[i][j] += (a[i][k]*b[k][j]);
				}
			}
		}
		return ans;
	};

	auto fast_exp = [&] (auto fast_exp, vector<vector<ll>> base, int exp) -> vector<vector<ll>>
	{
		if(exp == 0) return vector<vector<ll>> (n, vector<ll> (n, 1));
		if(exp == 1) return adj;

		vector<vector<ll>> ans = fast_exp(fast_exp, base, exp/2);
		ans = multiplication(ans, ans);
		if(exp & 1) ans = multiplication(ans, base);

		return ans;
	};

	vector<vector<ll>> sol = fast_exp(fast_exp, adj, k);

	print(sol);

	cout << sol[0][n-1] << "\n";
}
