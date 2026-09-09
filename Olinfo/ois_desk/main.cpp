#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l; cin >> n >> l;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	priority_queue<pair<int,int>> q;
	for(int i = 0; i < l-1; ++i) q.push({v[i], i});

	int ans = 1e9;
	for(int left = 0, right = l-1; right < n; left++, right++)
	{
		q.push({v[right], right});

		while(q.top().second < left) q.pop();
		auto a = q.top();
		int mx1 = a.first;
		q.pop();
		while(q.top().second < left) q.pop();
		auto b = q.top();
		int mx2 = b.first;
		q.pop();

		q.push(a);
		q.push(b);

		int dif = (mx1-mx2)/2;
		ans = min(ans, dif);
	}

	cout << ans << "\n";
}

