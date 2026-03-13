#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n);
	vector<bool> vis(n, false);
	for(int i = 0, b; i < n; ++i)
	{
		cin >> b;
		a[i] = b-1;
	}

	int idx;
	for(int i = 0; i < n; ++i)
	{
		fill(begin(vis), end(vis), false);
		idx = i;
		while(!vis[idx])
		{
			vis[idx] = true;
			idx = a[idx];
		}
		cout << idx+1 << " ";
	}
	cout << "\n";
}		
