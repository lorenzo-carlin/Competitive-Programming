#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int> (5));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			cin >> v[i][j];
		}
	}

	auto compare = [&] (int p1, int p2) -> int
	{
		int dom1 = 0, dom2 = 0;
		for(int j = 0; j < 5; ++j)
		{
			if(v[p1][j] < v[p2][j]) dom1++;
			else dom2++;
		}

		if(dom1 > dom2) return 1;
		else return 2;
	};

	int pot_win = 0;
	for(int i = 1; i < n; ++i)
	{
		int t = compare(pot_win, i);
		if(t == 2) pot_win = i;
	}

	bool impossible = false;
	for(int i = 0; i < n; ++i)
	{
		if(pot_win == i) continue;
		if(compare(pot_win, i) == 2) impossible = true;
	}

	if(impossible) cout << -1 << "\n";
	else cout << pot_win+1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
