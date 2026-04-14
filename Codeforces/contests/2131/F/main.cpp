#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n; cin >> n;
	string a, b; cin >> a >> b;
	
	vector<ll> pre_a(n);
	ll zeri = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] == '0') zeri++;
		pre_a[i] = (2*zeri - (i+1));
	}
	vector<ll> pre_b(n);
	ll uni = 0;
	for(int i = 0; i < n; ++i)
	{
		if(b[i] == '1') uni++;
		pre_b[i] = (2*uni - (i+1));
	}

	sort(begin(pre_a), end(pre_a));
	sort(begin(pre_b), end(pre_b));

	ll ans = 0;
	int p1 = 0, p2 = 0;
	while(p1 < n && p2 < n)
	{
		if(pre_a[p1] < pre_b[p2]) // se pre_a è il più piccolo
		{
			ans -= pre_a[p1]*(n-p2);
			ans += pre_a[p1]*(p2);
			p1++;
		} else // se pre_b è il più piccolo
		{
			ans -= pre_b[p2]*(n-p1);
			ans += pre_b[p2]*(p1);
			p2++;
		}
	}

	while(p1 < n)
    {
        ans -= pre_a[p1] * (n - p2);
        ans += pre_a[p1] * p2;
        p1++;
    }

    while(p2 < n)
    {
        ans -= pre_b[p2] * (n - p1);
        ans += pre_b[p2] * p1;
        p2++;
    }

	ll tot = n*n*(n+1)/2 - ans/2;

	cout << tot << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
