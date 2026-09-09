#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	int cur = -1, tot = 0;
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		if(cur == -1) cur = a;
		if(cur > a) cur = a;
		tot += cur;
		cur++;
	}

	cout << tot << "\n";
}
