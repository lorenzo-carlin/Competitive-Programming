#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 18;
int dp[MAXN][2][9];
bool memo[MAXN][2][9];

// smaller: 0 = non è più piccolo di v; 1 = è già più piccolo di v

int solve(int pos, bool smaller, int last, vector<int> &v)
{
	cout << pos << " " << smaller << " " << last << "\n";
	if(pos == v.size()-1) return 1;

	if(memo[pos][smaller][last]) return dp[pos][smaller][last];
	else memo[pos][smaller][last] = true;

	int ans = 0;

	int lim = (smaller) ? (9) : (v[pos]);
	for(int i = lim; i >= 0; i--)
	{
		if(i == last) continue;
		if(!smaller && v[pos] == i)
		{
			ans += solve(pos+1, false, i, v);
		} else
		{
			ans += solve(pos+1, true, i, v);
		}
	}

	cout << pos << " " << smaller << " " << last << " " << ans << "\n";

	return dp[pos][smaller][last] = ans;
}

int main()
{
	ll a, b; cin >> a >> b;
	a--;
	vector<int> A, B;
	while(a > 0)
	{
		A.push_back(a%10);
		a /= 10;
	}
	reverse(begin(A), end(A));
	while(b > 0)
	{
		B.push_back(b%10);
		b /= 10;
	}
	reverse(begin(B), end(B));

	for(int el: A) cout << el << " ";
	cout << "\n";
	for(int el: B) cout << el << " ";
	cout << "\n";

	int ans = solve(0, false, -1, B);

	cout << ans << "\n";
}	
