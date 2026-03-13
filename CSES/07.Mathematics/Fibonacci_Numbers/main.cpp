#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;
vector<vector<ll>> base = {{0, 1}, {1, 1}};

vector<vector<ll>> moltiplicazione(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> c(2, vector<ll> (2));
	c[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % mod;
	c[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % mod;
	c[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % mod;
	c[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % mod;
	return c;
}

vector<vector<ll>> binary_exp(vector<vector<ll>> b, ll exp)
{
	if(exp == 0 || exp == 1) return base;

	vector<vector<ll>> ans = binary_exp(b, exp/2);
	ans = moltiplicazione(ans, ans);
	if(exp & 1) ans = moltiplicazione(ans, base);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	if(n == 0)
	{
		cout << "0\n";
		return 0;
	}
	vector<vector<ll>> sol = binary_exp(base, n-1);
	cout << sol[1][1] << "\n";
}
