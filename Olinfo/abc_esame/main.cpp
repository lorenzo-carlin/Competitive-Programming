#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n; cin >> n;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	vector<int> dp1(n+5, 0), dp2(n+5, 0);
	// dp1: calcolata trascurando il primo valore
	for(int i = n-1; i > 0; i--)
	{
		dp1[i] = max(dp1[i], dp1[i+1]);
		dp1[i] = max(dp1[i], dp1[i+2]+v[i]);
	}

	// dp2: calcolata trascurando l'ultimo valore
	for(int i = n-2; i >= 0; i--)
	{
		dp2[i] = max(dp2[i], dp2[i+1]);
		dp2[i] = max(dp2[i], dp2[i+2]+v[i]);
	}

	cout << max(dp1[1], dp2[0]) << "\n";
}
