#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 5e4+5;
constexpr int MAXK = 21;
constexpr int LOG = 17;
constexpr int mod = 1e9+7;
ll dp[MAXN][MAXK];		// dp[i][j] = nr di modi in cui si possono creare j gruppi con i case
ll ps[MAXN+1][MAXK];	// ps[i][j] = dp[i-1][j] + dp[i-2][j] + ... + dp[0][j]

void precalculate()
{
	// DP
	for(int i = 0; i < MAXN; i++)
	{
		for(int j = 0; j < MAXK; j++)
		{
			if(j == 0)
			{
				dp[i][j] = 1;
			} else if(i == 0)
			{
				dp[i][j] = 0;
			} else
			{
				dp[i][j] = dp[i-1][j];
				dp[i][j] += ps[i][j-1];
			}
			ps[i+1][j] = ps[i][j] + dp[i][j];
			ps[i+1][j] %= mod;
		}
	}
}

int GCD(int a, int b)
{
	if(b == 0) return a;
	else return GCD(b, a%b);
}

int main()
{
	precalculate();

	int n, k; cin >> n >> k;
	vector<int> v(n, 100000);
	//for(int &i: v) cin >> i;

	// Sparse Table
	vector<vector<int>> ST(LOG, vector<int> (n, -1));
	for(int i = 0; i < n; ++i)
		ST[0][i] = v[i];
	for(int j = 1; j < LOG; ++j)
		for(int i = 0; i + (1 <<j) - 1 < n; ++i)
			ST[j][i] = GCD(ST[j-1][i], ST[j-1][i+(1<<(j-1))]);

	// Iterazione
	// calc(): calcola il GCD di tutti i numeri compresi tra v[a] e v[b]
	auto calc = [&] (int a, int b) -> ll
	{
		int w = log2(b-a+1);
		return GCD(ST[w][a], ST[w][b-(1<<w)+1]);
	};

	// find(): calcola l'indice j' tale che GCD(a, j') != GCD(a, b)
	auto find = [&] (int a, int b) -> int
	{
		int gcd = calc(a, b);
		int l = b+1, r = n;
		while(l < r)
		{
			int m = (l + r) / 2;
			if(calc(a, m) == gcd)
				l = m+1;
			else
				r = m;
		}
		return r;
	};

	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		vector<int> idx;
		int ind = i, next = find(i, ind);
		idx.push_back(ind);
		while(next != n)
		{
			ind = next;
			idx.push_back(ind);
			next = find(i, ind);
		}
		idx.push_back(n);

		int sz = idx.size();
		for(int j = 0; j < sz-1; ++j)
		{
			int x = idx[j];
			int y = idx[j+1]-1;
			ll tmp;
			for(int a = 0; a < k; a++)
			{
				tmp = 0;
				tmp += (ps[n-x][k-a-1]-ps[n-y-1][k-a-1]+mod);
				tmp %= mod;
				tmp *= dp[i][a];
				tmp %= mod;
				tmp *= calc(i, y);
				tmp %= mod;

				ans += tmp;
				ans %= mod;
			}
		}
	}

	cout << ans << "\n";
}
