#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	int sol = n;

	for(int i = 0; i < n; ++i)
	{
		if(v[i])
		{
			sol--;
			continue;
		}
		if(i != 0 && v[i-1] > 1)
		{
			v[i]++;
			sol--;
			v[i-1]--;
		} else if(i != n-1 && v[i+1] > 1)
		{
			v[i]++;
			sol--;
			v[i+1]--;
		}
	}

	cout << sol << "\n";
}
