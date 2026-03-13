#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, n; cin >> a >> b >> n;
	vector<int> f(n), s(n);
	for(auto &i: f) cin >> i;
	for(auto &i: s) cin >> i;
	sort(rbegin(f), rend(f));
	sort(begin(s), end(s));

	// BEST CASE
	int best_case = 1;
	multiset<int> ms;
	for(int i = 0; i < n; ++i)
	{
		ms.insert(s[i]);
	}
	for(int i = 0; i < n; ++i)
	{
		if(f[i] > a+b)
		{
			ms.erase(prev(ms.end()));
			best_case++;
		} else
		{
			int target = a+b-f[i];
			auto it = ms.upper_bound(target);
			if(it == ms.begin())
			{
				ms.erase(prev(ms.end()));
				best_case++;
			} else
			{
				it--;
				ms.erase(it);
			}
		}
	}

	cout << best_case << " ";

	// WORST CASE
	int worst_case = 1;
	ms.clear();
	for(int i = 0; i < n; ++i)
	{
		ms.insert(s[i]);
	}
	for(int i = 0; i < n; ++i)
	{
		int target = a+b-f[i];
		auto it = ms.upper_bound(target);
		if(it == ms.end()) continue;
		ms.erase(it);
		worst_case++;
	}

	cout << worst_case << "\n";
}
