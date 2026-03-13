#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int ans = 0;
	for(int i = 0, a, b, c; i < n; ++i)
	{
		cin >> a >> b >> c;
		if(a+b+c >= 2) ans++;
	}
	
	cout << ans << "\n";
}
