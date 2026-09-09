#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	vector<int> v(n), cnt(10, 0);
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		cnt[a]++;
	}

	v[0] = 0;
	cnt[0]--;
	if(cnt[0] != 0)
	{
		v[1] = 0;
		cnt[0]--;
	} else if(cnt[2] != 0)
	{
		v[1] = 2;
		cnt[2]--;
	} else if(cnt[4] != 0)
	{
		v[1] = 4;
		cnt[4]--;
	} else if(cnt[6] != 0)
	{
		v[1] = 6;
		cnt[6]--;
	} else
	{
		v[1] = 8;
		cnt[8]--;
	}

	int ind = 0;
	for(int i = 2; i < n; ++i)
	{
		while(cnt[ind] == 0) ind++;
		v[i] = ind;
		cnt[ind]--;
	}

	for(int i = n-1; i >= 0; i--)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}
