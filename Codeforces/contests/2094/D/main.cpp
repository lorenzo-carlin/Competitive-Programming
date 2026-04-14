#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	string p, s; cin >> p >> s;
	vector<int> P, S;
	int cnt = 0;
	for(int i = 0; i < p.size()-1; ++i)
	{
		cnt++;
		if(p[i] != p[i+1])
		{
			P.push_back(cnt);
			cnt = 0;
		}
	}
	if(p[p.size()-2] == p[p.size()-1])
	{
		P.push_back(cnt+1);
	} else
	{
		P.push_back(1);
	}
	cnt = 0;
	for(int i = 0; i < s.size()-1; ++i)
	{
		cnt++;
		if(s[i] != s[i+1])
		{
			S.push_back(cnt);
			cnt = 0;
		}
	}
	if(s[s.size()-2] == s[s.size()-1])
	{
		S.push_back(cnt+1);
	} else
	{
		S.push_back(1);
	}

	if(P.size() != S.size() || p[0] != s[0])
	{
		cout << "NO\n";
		return;
	}

	for(int i = 0; i < P.size(); ++i)
	{
		if(S[i] < P[i] || S[i] > 2*P[i])
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
