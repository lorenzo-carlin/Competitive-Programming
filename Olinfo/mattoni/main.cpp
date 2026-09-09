#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int> sline(n+1, 0);
	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		a--; b--;
		sline[a]++;
		sline[b+1]--;
	}
	vector<int> values(n, 0);
	int cur = 0;
	for(int i = 0; i < n; ++i)
	{
		cur += sline[i];
		values[i] = cur;
	}

	sort(begin(values), end(values));
	cout << values[n/2] << "\n";
}
