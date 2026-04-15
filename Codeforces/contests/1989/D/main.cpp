#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e6+6;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int> a(n), b(n);
	for(int &i: a) cin >> i;
	for(int &i: b) cin >> i;

	vector<array<int,3>> v;
	for(int i = 0; i < n; ++i)
	{
		v.push_back({a[i], a[i]-b[i], b[i]});
	}
	sort(begin(v), end(v));

	vector<int> mnn(n), A(n);
	mnn[0] = v[0][1];
	A[0] = v[0][0];
	for(int i = 1; i < n; i++)
	{
		mnn[i] = min(mnn[i-1], v[i][1]);
		A[i] = v[i][0];
	}

	vector<int> dp(MAXN, 0);
	for(int i = 0; i < MAXN; i++)
	{
		int range = upper_bound(begin(A), end(A), i)-begin(A);
		if(range == 0) continue;
		range--;
		int mn = mnn[range];
		dp[i] = dp[i-mn]+1;
	}

	ll tot = 0;
	vector<int> c(m);
	for(int &i: c) cin >> i;
	for(int i = 0; i < m; ++i)
	{
		if(c[i] > 1e6)
		{
			int tagli = (c[i]-1e6)/mnn.back() + 1;
			c[i] -= (tagli*mnn.back());
			tot += tagli;
		}
		tot += dp[c[i]];
	}
	cout << tot*2 << "\n";
}
