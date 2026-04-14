#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e5+5;
vector<int> prime(MAXN, 1);

void sieve()
{
	for(int i = 2; i < MAXN; ++i)
	{
		if(prime[i] == 1) // se è primo
		{
			for(int j = i; j < MAXN; j += i)
			{
				prime[j] = i;
			}
		}
	}
}

void solve()
{
	int n; cin >> n;
	vector<int> ans(n, -1);
	ans[0] = 1;
	for(int i = n; i > 1; i--)
	{
		if(prime[i] == i) // se è primo
		{
			int last = i;
			for(int j = 2*i; j <= n; j += i)
			{
				if(ans[j-1] != -1) continue;
				ans[j-1] = last;
				last = j;
			}
			ans[i-1] = last;
		}
	}

	for(auto el: ans) cout << el << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	int t; cin >> t;
	while(t--) solve();
}
