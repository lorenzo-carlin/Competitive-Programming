#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int ans = 0;
	for(int i = 2; i <= n; i++)
	{
		bool cond = true;
		for(int j = 2; j*j <= i; j++)
		{
			if(i % j == 0)
			{
				cond = false;
			}
		}
		if(cond) ans++;
	}

	cout << ans << "\n";
}
