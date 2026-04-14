#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, s; cin >> n >> s;
	int zero = 0, uno = 0, due = 0;
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		if(a == 0) zero++;
		if(a == 1) uno++;
		if(a == 2) due++;
	}

	int sum = uno + 2*due;
	int rem = s - sum;
	// cout << "rem: " << rem << "\n";

	if(rem < 0) // vinciamo sempre
	{
		for(int i = 0; i < zero; ++i) cout << 0 << " ";
		for(int i = 0; i < due; ++i) cout << 2 << " ";
		for(int i = 0; i < uno; ++i) cout << 1 << " ";
		cout << "\n";
		return;
	}
	if(rem == 0) // perdiamo sempre
	{
		cout << -1 << "\n";
		return;
	}
	if(rem > 0 && rem % 2 == 0) // perdiamo sempre
	{
		cout << -1 << "\n";
		return;
	}
	if(rem > 0 && rem % 2 == 1 && rem < 3) // vinciamo sempre
	{
		for(int i = 0; i < zero; ++i) cout << 0 << " ";
		for(int i = 0; i < due; ++i) cout << 2 << " ";
		for(int i = 0; i < uno; ++i) cout << 1 << " ";
		cout << "\n";
		return;
	}
	cout << -1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
