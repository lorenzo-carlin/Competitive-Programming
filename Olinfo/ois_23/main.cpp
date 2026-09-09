#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int dim = 30;
vector<int> base2(dim, 0), base3(dim, 0);
int sumbase2 = 0, sumbase3 = 0;

void incremento()
{
	int idx = 0;
	while(base2[idx] == 1)
	{
		base2[idx] = 0;
		sumbase2 -= 1;
		idx++;
	}
	base2[idx]++;
	sumbase2++;

	idx = 0;
	while(base3[idx] == 2)
	{
		base3[idx] = 0;
		sumbase3 -= 2;
		idx++;
	}
	base3[idx]++;
	sumbase3++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	vector<pair<int,int>> v;
	for(int i = 0, a; i < t; i++)
	{
		cin >> a;
		v.push_back({a, i});
	}
	sort(begin(v), end(v));
	vector<int> sol(t);

	int ind = 0, ans = 0;
	for(int i = 0; i < t; i++)
	{
		while(ind < v[i].first)
		{
			incremento();
			ind++;
			if(sumbase2 == sumbase3) ans++;
		}
		sol[v[i].second] = ans;
	}

	for(int i = 0; i < t; i++)
	{
		cout << sol[i] << " \n"[i == t-1];
	}
}	
