#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// IDEA:
	// dp[i]: costo minimo per spedire 'i' pacchetti
	// dp[i] = MIN(dp[i-k] + dp[k] per ogni 1 <= k < i)
	// dp[i] = MIN(dp[i], perimetro minimo per un blocco di 'i' pacchetti
	

	int n; cin >> n;
	
	vector<int> dp(n+1, 1e9);
	dp[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j*j <= n; ++j)
		{
			if(i % j != 0) continue;
			dp[i] = min(dp[i], 2*j + 2*(i/j));
		}

		for(int k = 1; k <= i/2; ++k)
		{
			dp[i] = min(dp[i], dp[k]+dp[i-k]);
		}
	}

	cout << dp.back() << "\n";
}
