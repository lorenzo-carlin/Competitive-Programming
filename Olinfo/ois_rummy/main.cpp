#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<ll> v(n+2);
	for(ll &i: v) cin >> i;

	vector<ll> ps(n+2, 0);
	ps[0] = v[0];
	for(int i = 1; i < n+2; ++i)
	{
		ps[i] = ps[i-1] + v[i];
	}

	vector<ll> pss(n+2, 0);
	pss[0] = ps[0];
	for(int i = 1; i < n+2; ++i)
	{
		pss[i] = pss[i-1] + ps[i];
	}

	for(int i = 1; i < n; ++i)
	{
		pss[i] = max(pss[i], pss[i-1]*(i+1)/(i));
	}

	if(pss[n] >= pss[n-1]*(n+1)/(n))
	{
		cout << "YES\n";
	} else
	{
		cout << "NO\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}


