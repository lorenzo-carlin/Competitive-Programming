/*
 * Euler's Totient Function
 * Computes the number of integers from 1 to n that are coprime with n.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5+5;
int phi[MAXN];

void precompute()
{
	for(int i = 1; i < MAXN; ++i) phi[i] = i;
	for(int i = 2; i < MAXN; ++i)
	{
		if(phi[i] == i)
		{
			for(int j = i; j < MAXN; j+=i)
			{
				phi[j] -= (phi[j]/i);
			}
		}
	}
}
