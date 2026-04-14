#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2e5+5;

int sumDigits(int n)
{
	int ans = 0;
	while(n > 0)
	{
		ans += (n % 10);
		n = n/10;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<ll> v(MAXN); v[0] = 1;
	for(int i = 1; i < MAXN; ++i)
	{
		v[i] = v[i-1] + sumDigits(i+1);
	}

	int t; cin >> t;
	while(t--)
	{
		int num; cin >> num;
		cout << v[num-1] << "\n";
	}
}

