#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	int uno = 0, due = 0;;
	for(int i = 0; i < n; ++i)
	{
		if(v[i] == 1) uno++;
		if(v[i] == 2) due++;
	}

	double ris = (double) due*(due+1.0)/(2.0*(uno+2.0*due));
	cout << ris << "\n";
}
