#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string s; cin >> s;

	vector<int> cnt0(n+1, 0), cnt1(n+1, 0);
	for(int i = 1; i <= n; ++i)
	{
		cnt0[i] = cnt0[i-1];
		cnt1[i] = cnt1[i-1];
		if(s[i-1] == '0') cnt0[i]++;
		else cnt1[i]++;
	}

	vector<int> balance(n+1);
	map<int,int> first_app;
	int mx = 0;
	for(int i = 0; i <= n; ++i)
	{
		balance[i] = cnt1[i] - cnt0[i];
		if(!first_app.count(balance[i])) first_app[balance[i]] = i;
		else
		{
			mx = max(mx, i - first_app[balance[i]]);
		}
	}

	cout << mx << "\n";
}	
