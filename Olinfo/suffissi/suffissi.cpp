#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int> a(n), ans(n);
	for(int &i: a) cin >> i;

	set<int> s;
	for(int i = n-1; i >= 0; i--)
	{
		s.insert(a[i]);
		ans[i] = s.size();
	}

	int p;
	while(m--)
	{
		cin >> p;
		cout << ans[p-1] << "\n";
	}
}
