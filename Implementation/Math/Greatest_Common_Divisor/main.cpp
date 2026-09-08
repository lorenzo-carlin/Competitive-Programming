/*
 * Greatest Common Divisor (GCD)
 * Computes the greatest common divisor of two integers using the Euclidean algorithm.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int GCD(int a, int b)
{
	if(b == 0) return a;
	else return GCD(b, a%b);
}

int LCM(int a, int b)
{
	int gcd = GCD(a, b);
	return a*b/gcd;
}
