#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int &i: a) cin >> i;
	for(int &i: b) cin >> i;

	int plus = 0, minus = 0;
	int totA = 0, totB = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > b[i]) totA += a[i];
		else if(a[i] < b[i]) totB += b[i];
		else if(a[i] == 1 && b[i] == 1) plus++;
		else if(a[i] == -1 && b[i] == -1) minus++;
	}

	int minn = min(totA, totB);
	int maxx = max(totA, totB);

	// cout << minn << " " <<  maxx << "\n";

	int tmp = min(maxx-minn, plus);
	minn += tmp;
	plus -= tmp;
	if(plus)
	{
		minn += (plus/2);
		maxx += ((plus+1)/2);
	}

	// cout << minn << " " <<  maxx << "\n";

	tmp = min(maxx-minn, minus);
	maxx -= tmp;
	minus -= tmp;
	if(minus)
	{
		minn -= ((minus+1)/2);
		maxx -= (minus/2);
	}
	// cout << minn << " " << maxx << "\n";

	cout << min(minn, maxx) << "\n";
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
