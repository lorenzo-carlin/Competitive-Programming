#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k; cin >> n >> k;
	int mn = 1e9;

	bitset<5005> bit;
	vector<int> p(n);
	for(auto &i: p) cin >> i;
	bit[0] = 1;

	for(int i = 0; i < n; ++i)
	{
		vector<int> s;
		for(int j = 0; j < k; ++j)
		{
			if(bit[j] == 0) continue;
			int target = j+p[i];
			if(target >= k)
			{
				mn = min(mn, target);
				break;
			} else
			{
				s.push_back(target);
			}
		}
		for(int el: s)
		{
			bit[el] = 1;
		}
	}

	cout << mn << "\n";
}
