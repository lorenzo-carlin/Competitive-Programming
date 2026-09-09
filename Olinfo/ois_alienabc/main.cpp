#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		set<string> p;
		string cur;
		vector<string> ans;
		bool cond = true;
		for(int i = 0; i < s.size()-1; ++i)
		{
			if(!cond) break;

			cur += s[i];
			if(s[i] == s[i+1] && cur.size() == 1) continue;
			if(s[i] == s[i+1] && cur.size() == 2)
			{
				if(p.count(cur))
				{
					cond = false;
					break;
				} else
				{
					ans.push_back(cur);
					p.insert(cur);
					cur.clear();
				}
			} else if(s[i] != s[i+1])
			{
				if(p.count(cur))
				{
					cond = false;
					break;
				} else
				{
					ans.push_back(cur);
					p.insert(cur);
					cur.clear();
				}
			}
		}
		cur += s.back();
		if(p.count(cur))
		{
			cond = false;
		} else
		{
			ans.push_back(cur);
		}

		if(cond)
		{
			for(auto el: ans) cout << el << " ";
			cout << "\n";
		} else
		{
			cout << -1 << "\n";
		}
	}
}
