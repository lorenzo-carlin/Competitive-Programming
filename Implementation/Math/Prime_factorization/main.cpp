/*
 * Prime Factorization
 * Decomposes an integer into its prime factors and their corresponding
 * multiplicities.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> factor(int n)
{
	vector<int> ans;
	for(int i = 2; i*i <= n; ++i)
	{
		while(n % i == 0)
		{
			ans.push_back(i);
			n /= i;
		}
	}
	if(n > 1) ans.push_back(n);
	return ans;
}
