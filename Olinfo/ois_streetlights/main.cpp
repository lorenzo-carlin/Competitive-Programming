#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	int ans = 0;

	int sum = 0;
	stack<int> s;
	int l = 0, r = m-1;
	for(int i = 0; i < m-1; ++i)
	{
		if(v[i]) sum++;
		else s.push(i);
	}

	for(; r < n; l++, r++)
	{
		if(v[r] == 1) sum++;
		else s.push(r);

		while(sum < k)
		{
			v[s.top()] = 1;
			s.pop();
			sum++;
			ans++;
		}

		if(v[l] == 1) sum--;
	}

	cout << ans << "\n";
}
