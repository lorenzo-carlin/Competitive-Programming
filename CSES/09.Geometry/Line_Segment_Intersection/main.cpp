#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct pt
{
	ll x, y;
 
	pt() {}
	pt(ll a, ll b): x(a), y(b) {}
};
 
pt operator +(const pt &a, const pt &b) { return pt(a.x + b.x, a.y + b.y); }
pt operator -(const pt &a, const pt &b) { return pt(a.x - b.x, a.y - b.y); }
 
int sign(ll n)
{
	if(n == 0) return  0;
	if(n  > 0) return  1;
	return -1;
}
 
ll dot(pt a, pt b)
{
	return a.x * b.x + a.y * b.y;
}
 
ll cross(pt a, pt b)
{
	return a.x * b.y - a.y * b.x;
}
 
struct line
{
	pt v; ll c;
	
	line() {}
	line(pt a, pt b): v(b - a), c(cross(v, b)) {}
};
 
ll side(pt a, pt b, pt p)
{
	return cross(b-a, p-a);
}
 
ll side(line l, pt p)
{
	return cross(l.v, p) - l.c;
}
 
ll orient(pt a, pt b, pt c)
{
	return cross(b-a, c-a);
}
 
bool onSegment(pt a, pt b, pt p)
{
	return orient(a, b, p) == 0 && dot(a-p, b-p) <= 0;
}
 
int main()
{
	int n; cin >> n;
	while(n--)
	{
		pt a, b, c, d;
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		cin >> c.x >> c.y;
		cin >> d.x >> d.y;
 
		line AB = line(a, b);
		line CD = line(c, d);
 
		if((sign(side(a, b, c)) != sign(side(a, b, d))) && (sign(side(c, d, a)) != (sign(side(c, d, b)))))
		{
			cout << "YES\n";
		} else if(side(AB, c) == 0 && side(AB, d) == 0 && (onSegment(c, d, a) || onSegment(c, d, b) || onSegment(a, b, c) || onSegment(a, b, d)))
		{
			cout << "YES\n";
		} else
		{
			cout << "NO\n";
		}
	}
}
