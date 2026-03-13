#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, k; cin >> n >> k;

	if(k == 0)
	{
		cout << 0 << "\n";
		return;
	}

	int sol = 1, cur = n-1;
	k -= n;

	while(k > 0)
	{
		k -= cur;
		sol++;
		
		if(k <= 0) break;

		k -= cur;
		sol++;

		cur--;
	}

	cout << sol << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
