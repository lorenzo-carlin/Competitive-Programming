#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int compila(int d, int x, int n, int s)
{
	int ans = (max(0, x-(d-(n*s)))+s-1)/s;
	return ans;
}
