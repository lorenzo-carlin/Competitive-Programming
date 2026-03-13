#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<pair<int,int>> pol;
	for(int i = 0; i < n; ++i)
	{
		bool cond = false;
		for(int j = 0; j < n; ++j)
		{
			char c; cin >> c;
			int num = (c == '1') ? (1) : (0);
			if(num == 1 && !cond)
			{
				pol.push_back({j, 0});
				cond = true;
			}
			if(num == 0 && cond)
			{
				pol.back().second = j-1;
				cond = false;
			}
		}
		if(cond) pol.back().second = n-1;
	}
	set<int> st, fn;
	for(auto el: pol)
	{
		st.insert(el.first);
		fn.insert(el.second);
	}
	if(st.size() == 1 && fn.size() == 1)
	{
		cout << "SQUARE\n";
	} else
	{
		cout << "TRIANGLE\n";
	}
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}

