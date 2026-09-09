#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k; cin >> n >> k;
	vector<pair<float,int>> v;
	for(int i = 0; i < n; ++i)
	{
		float a, b; cin >> a >> b;
		v.push_back({a-(3.0/2.0*b), i});
	}

	sort(rbegin(v), rend(v));
	for(int i = 0; i < k; ++i)
	{
		cout << v[i].second+1 << "\n";
	}
}
