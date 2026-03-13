#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P
{
	ll x, y;
	P() {}
	P(ll a, ll b) : x(a), y(b) {}
};

P operator +(const P &a, const P &b)
{
	return P(a.x+b.x, a.y+b.y);
}

P operator -(const P &a, const P &b)
{
	return P(a.x-b.x, a.y-b.y);
}

int sign(ll num)
{
	if(num == 0) return 0;
	if(num > 0) return 1;
	return -1;
}

ll dot(P a, P b)
{
	return a.x * b.x + a.y * b.y;
}

ll cross(P a, P b)
{
	return a.x * b.y - a.y * b.x;
}

ll side(P a, P b, P c)
{
	// da che parte sta il punto c rispetto alla retta ab
	return cross(b-a, c-a);
}

bool onSegment(P a, P b, P c)
{
	// controlla se il punto c sta sul segmento ab
	return side(a, b, c) == 0 && dot(a-c, b-c) <= 0;
}

bool intersection(P a, P b, P c, P d)
{
	if(sign(side(a, b, c)) != sign(side(a, b, d)) && sign(side(c, d, a)) != sign(side(c, d, b))) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<P> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].x >> v[i].y;
	}

	for(int i = 0; i < m; ++i)
	{
		P c;
		cin >> c.x >> c.y;
		P d = c + P(2e9, 1);

		int intersections = 0;
		bool cond = false;
		for(int j = 0; j < n-1; ++j)
		{
			// se giace sulla retta
			if(onSegment(v[j], v[j+1], c))
			{
				cond = true;
			}

			// controllo se cd interseca ab
			if(intersection(v[j], v[j+1], c, d))
			{
				intersections++;
			}
		}
		if(onSegment(v.back(), v.front(), c))
		{
			cond = true;
		}
		if(intersection(v.back(), v.front(), c, d))
		{
			intersections++;
		}

		if(cond)
		{
			cout << "BOUNDARY\n";
		} else if(intersections & 1)
		{
			cout << "INSIDE\n";
		} else
		{
			cout << "OUTSIDE\n";
		}
	}
}
