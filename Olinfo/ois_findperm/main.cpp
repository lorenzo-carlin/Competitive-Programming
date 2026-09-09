#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

constexpr int LOG = 10;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> v(n, 0);
	vector<int> pot(LOG, -1);

	for(int i = 0; i < n; ++i)
	{
		cout << "? " << i+1 << " " << i+1 << "\n";
		int t; cin >> t;
		pot[t] = i;
	}

	for(int j = 0; j < LOG; ++j)
	{
		if(pot[j] == -1) continue;
		for(int i = 0; i < n; ++i)
		{
			cout << "? " << i+1 << " " << pot[j]+1 << "\n";
			int t; cin >> t;
			if(t == j) v[i] += (1 << j);
		}
	}

	cout << "! ";
	for(int el: v) cout << el << " ";
	cout << "\n";
	cout.flush();
}
