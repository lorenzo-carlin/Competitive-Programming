#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int cur = 0, mx = 0;
	while(n--)
	{
		int tmp; cin >> tmp;
		mx = max(mx, tmp - cur);
		cur = tmp;
	}

	cout << mx << "\n";
}
