#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b; cin >> a >> b;
	int sol = 0;
	set<pair<int,int>> s;
	while(a != 1 || b != 1)
	{
		if(s.count({a, b}) || s.count({b, a}))
		{
			sol = -1;
			break;
		}

		s.insert({a, b});
		if((a & 1) && (b & 1))
		{
			a *= 3;
			a++;
			b *= 3;
			b++;
		} else if(!(a & 1) && !(b & 1))
		{
			a /= 2;
			b /= 2;
		} else
		{
			if(a & 1) a += 3;
			else b += 3;
		}
		sol++;

		if(sol > 1e9)
		{
			sol = -1;
			break;
		}
	}

	cout << sol << "\n";
}
