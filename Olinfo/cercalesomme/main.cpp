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
	vector<int> v(n);
	for(int &i: v) cin >> i;
	int k; cin >> k;

	auto solve = [&] (auto solve, int i, int sum, string s, vector<int> ans)
	{
		if(i == n)
		{
			if(sum == 0 && s.empty())
			{
				for(int i = 0; i < ans.size()-1; i++) cout << ans[i] << " ";
				cout << "\n";
			}
			return;
		}

		if(sum < 0) return;

		s += to_string(v[i]);

		// non tronco
		solve(solve, i+1, sum, s, ans);

		// tronco
		sum -= stoi(s);
		ans.push_back(i+1);
		s.clear();
		solve(solve, i+1, sum, s, ans);
	};

	solve(solve, 0, k, "", {});
}
