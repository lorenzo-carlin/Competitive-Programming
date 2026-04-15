#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(int x, int y)
{
	int dist = abs(x-0);
	int finalX = x;
	int finalY = -x;

	if(y-x+1 >= finalY) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for(int i = 0, x, y; i < n; ++i)
	{
		cin >> x >> y;
		if(possible(x, y)) cout << "YES\n";
		else cout << "NO\n";
	}
}
