#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> bilancia(int n, int m, vector<vector<int>> s)
{
	vector<pair<int,vector<int>>> v(m);
	for(int i = 0; i < m; ++i)
	{
		v[i].first = i;
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < s[i].size(); ++j)
		{
			v[s[i][j]].second.push_back(i);
		}
	}

	sort(begin(v), end(v), [](pair<int,vector<int>> a, pair<int,vector<int>> b)
	{
		return a.second.size() > b.second.size();
	});

	set<int> ss;
	for(int i = 0; i < n; ++i)
	{
		ss.insert(i);
	}

	set<int> nw;
	vector<int> ans;
	for(int i = 0; i < m; ++i)
	{
		nw.clear();
		ans.push_back(v[i].first);
		for(int j = 0; j < v[i].second.size(); ++j)
		{
			if(!ss.count(v[i].second[j]))
			{
				return {};
			}
			nw.insert(v[i].second[j]);
		}
		swap(ss, nw);
	}

	return ans;
}
