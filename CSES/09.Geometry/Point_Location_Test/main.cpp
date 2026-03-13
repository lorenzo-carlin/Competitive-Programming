#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct pt
{
	ll x, y;

	pt() {}
	pt(ll a, ll b) : x(a), y(b) {}
};

pt operator -(pt a, pt b) 
{
	return pt((a.x - b.x), (a.y - b.y));
}

ll cross(pt a, pt b)
{
	return a.x * b.y - a.y * b.x;
}

int main()
{
	int n; cin >> n;

	while(n--)
	{
		pt a, b, c;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
		ll ans = cross((b-a), (c-a));
		if(ans > 0) cout << "LEFT\n";
		else if(ans == 0) cout << "TOUCH\n";
		else cout << "RIGHT\n";
	}
}
