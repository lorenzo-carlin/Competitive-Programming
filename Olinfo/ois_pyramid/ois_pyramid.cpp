#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int layer = 0;
	for(int i = 1; n >= 0; i++)
	{
		layer++;
		n -= (i*i);
	}

	cout << layer-1 << "\n";
}
