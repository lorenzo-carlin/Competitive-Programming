#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q; cin >> n >> q;
	vector<int> v(n), idx(50, 1e9);
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		a--;
		idx[a] = min(idx[a], i);
	}

	for(int i = 0, a; i < q; ++i)
	{
		cin >> a;
		a--;
		cout << idx[a]+1 << " ";
		int tmp = idx[a];
		for(int j = 0; j < 50; ++j)
		{
			if(idx[j] < tmp) idx[j]++;
		}
		idx[a] = 0;
	}
	
	cout << "\n";
}
