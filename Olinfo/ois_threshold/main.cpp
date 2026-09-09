#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> v(100, 0);
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		v[a]++;
	}

	int sol = 0;
	for(int i = 100; i >= 0; i--)
	{
		sol += v[i];
		cout << sol << " ";
	}
	cout << "\n";
}
