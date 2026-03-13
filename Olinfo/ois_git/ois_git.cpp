#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e6;
int tmr = 1;
map<string,int> code;
map<int,string> code1;
vector<set<int>> adj;
vector<bool> state;

string codifica(string s)
{
	vector<string> path;
	string tmp;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == "/")
		{
			path.push_back(tmp);
			tmp.clear();
		}
		tmp += s[i];
	}
	path.push_back(tmp);

	for(auto el: path)
	{
		if(!code.count(el))
		{
			code[el] = tmr++;
		}
	}

	int last = 0;
	for(int i = 0; i < path.size(); ++i)
	{
		int nuovo = code[path[i]];
		adj[last].insert(nuovo);
		adj[nuovo].insert(last);
	}

	return path.back();
}

int main()
{
	int n; cin >> n;
	adj.resize(n+1);
	state.resize(MAXN, false);
	for(int i = 0; i < n; ++i)
	{
		int t; cin >> t;
		string s; cin >> s;
		s = codifica(s);
		if(t == 1) state[code[s]] = true;
		else state[code[s]] = false;
	}

	auto dfs = [&] (auto dfs, int v, int p, string path) -> void
	{
		bool cond = true;
		vector<int> changed;
		for(auto u: adj[v])
		{
			dfs(dfs, v, p, path+
			if(state[u])
			{
				changed.push_back(u);
			} else
			{
				cond = false;
			}
		}

		if(!cond)
		{




