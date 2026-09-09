#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	map<int,int> st, fn;
	for(int i = 0, a, b; i < n; ++i)
	{
		cin >> a >> b;
		st[a]++;
		fn[b]++;
	}

	int presenti = 0, tot = 0;
	auto it = fn.begin();
	for(auto el: st)
	{
        while(it != fn.end() && (*it).first < el.first)
		{
			presenti -= (*it).second;
			it++;
		}

		tot += (el.second*(presenti+el.second));
		presenti += el.second;
	}

	cout << tot << "\n";
}
