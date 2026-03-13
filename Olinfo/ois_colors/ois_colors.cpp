#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;

	vector<int> scelte(n, 0);
	ll ans = 1, col_rimasti = k;
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		if(a == 0)
		{
			ans *= col_rimasti;
			ans %= mod;
			col_rimasti--;
		} else
		{
			ans *= scelte[a-1];
			ans %= mod;
			scelte[a-1]--;
		}
		scelte[a]++;
	}

	cout << ans << "\n";
}
