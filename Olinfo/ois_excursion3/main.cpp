#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, f, m; cin >> a >> f >> m;
	int s = m+f-a;

	cout << (3*f+2*m+a) << "\n";
	cout << (1*f+1*m+a) << "\n";
}
