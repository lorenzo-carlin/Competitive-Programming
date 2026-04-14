#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	vector<int> p;
	for(int i = 0; i < n-1; ++i)
	{
		if(v[i] == v[i+1]) continue;
		p.push_back(v[i]);
	}
	p.push_back(v.back());

	int ans = 0;
	for(int i = 0; i < p.size(); ++i)
	{
		if(i == 0 && p[i] > p[i+1]) ans++;
		else if(i == p.size()-1 && p[i] > p[i-1]) ans++;
		else if(p[i] > p[i-1] && p[i] > p[i+1]) ans++;
	}
	if(p.size() == 1) ans = 1;

	cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
