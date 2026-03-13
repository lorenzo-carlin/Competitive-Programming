#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string a, b; cin >> a >> b;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] == b[i] && b[i] == 'R')
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout << n << "\n";
}
