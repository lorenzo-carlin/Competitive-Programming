#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve(int tot, int last, vector<int> sol)
{
	if(tot > n) return;
	if(tot == n)
	{
		for(int el: sol)
		{
			cout << el << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = 1; i <= last; i++)
	{
		sol.push_back(i);
		solve(tot+i, i, sol);
		sol.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	solve(0, n, {});
}
