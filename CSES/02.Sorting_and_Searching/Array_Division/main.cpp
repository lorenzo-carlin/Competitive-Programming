#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v;
int n, k;

bool possible(ll num)
{
	ll sum = 0;
	int ind = 1;
	for(int i = 0; i < n; ++i)
	{
		if(sum + v[i] > num)
		{
			sum = v[i];
			ind++;
		} else
		{
			sum += v[i];
		}
	}

	if(ind <= k) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	ll tot = 0;
    int	mx = 0;
	v.resize(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		tot += v[i];
		mx = max(mx, v[i]);
	}

	ll l = mx, r = tot;
	while(l < r)
	{
		ll m = (l + r)/2;
		if(possible(m))
		{
			r = m;
		} else
		{
			l = m+1;
		}
	}

	// cout << l << " " << r << "\n";

	if(possible(r)) cout << r << "\n";
	else cout << r+1  << "\n";
}
