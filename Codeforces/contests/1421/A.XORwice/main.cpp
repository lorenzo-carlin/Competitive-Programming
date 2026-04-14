#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int a, b; cin >> a >> b;
	int ans = 0;
	
	/*
	 * OSS:
	 * se c'è un bit che è 1 in entrambi, lo accendo così si rimuove in entrambi
	 * se c'è nu bit che è 0 in entrambi, lo lascio spento
	 * se c'è un bit acceso in uno e spento nell'altro, se lo accendo faccio +k-k, se lo spengo idem, non cambia nulla
	 */

	for(int i = 0; i < 32; ++i)
	{
		if((a & (1 << i)) && (b & (1 << i)))
			ans += (1 << i);
	}

	cout << (a^ans)+(b^ans) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
