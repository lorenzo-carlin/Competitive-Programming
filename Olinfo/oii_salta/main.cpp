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
	vector<int> v(n+1);
	for(int i = 1; i <= n; ++i) cin >> v[i];

	vector<bool> vis(n+1, false);
	vis[0] = true;
	int ind = 1;
	while(!vis[ind])
	{
		vis[ind] = true;
		ind = (ind + v[ind]) % n + 1;
	}

	int ans = 0;
	vector<int> sol;
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			ans++;
			sol.push_back(i);
		}
	}

	cout << ans << "\n";
	for(int el: sol) cout << el << " ";
	cout << "\n";
}
