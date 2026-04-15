#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<vector<ll>> pref1(n, vector<ll> (26, 0)); // pref sums su indici pari
    vector<vector<ll>> pref2(n, vector<ll> (26, 0)); // pref sums su indici dispari
	
	string s; cin >> s;
	if(n == 1)
	{
		cout << 1 << "\n";
		return;
	}

	for(int i = 0; i < n; i++)
	{
		if(i > 0)
		{
			pref1[i] = pref1[i-1];
			pref2[i] = pref2[i-1];
		}

		if(i & 1)
		{
			pref2[i][s[i]-'a']++;
		} else
		{
			pref1[i][s[i]-'a']++;
		}
	}

	ll ans = 1e9;
	if(n & 1)
	{
		for(int i = 0; i < n; ++i) // scelgo quale indice togliere
		{
			// indici pari
			ll pari = 0;
			for(int j = 0; j < 26; ++j)
			{
				ll cur = 0;
				if(i > 0) cur += pref1[i-1][j];
				cur += (pref2[n-1][j] - pref2[i][j]);
				pari = max(pari, cur);
			}
			ll dispari = 0;
			for(int j = 0; j < 26; ++j)
			{
				ll cur = 0;
				if(i > 0) cur += pref2[i-1][j];
				cur += (pref1[n-1][j] - pref1[i][j]);
				dispari = max(dispari, cur);
			}
			ans = min(ans, (n-1)-pari-dispari+1);
		}
	} else
	{
		ll pari = 0, dispari = 0;
		for(int j = 0; j < 26; ++j)
		{
			pari = max(pari, pref1[n-1][j]);
			dispari = max(dispari, pref2[n-1][j]);
		}
		ans = n-pari-dispari;
	}

	cout << ans << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
