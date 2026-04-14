#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	vector<int> pre(n), suf(n);
	pre[0] = v[0];
	for(int i = 1; i < n; ++i) pre[i] = min(pre[i-1], v[i]);
	suf[n-1] = v[n-1];
	for(int i = n-2; i >= 0; i--) suf[i] = max(suf[i+1], v[i]);

	string s;
	for(int i = 0; i < n; ++i)
	{
		if(pre[i] == v[i] || suf[i] == v[i]) s += '1';
		else s += '0';
	}

	cout << s << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
