#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	string substring, subsequence;
	cin >> substring;
	cin >> subsequence;
	int dimSubstring = substring.size();
	int dimSubsequence = subsequence.size();

	int mx = -1;
	for(int i = 0; i < dimSubsequence; i++)
	{
		for(int j = i; j < dimSubsequence; j++)
		{
			string s = subsequence.substr(i, j-i+1);
			int dimS = j-i+1;
			int ind = 0;
			for(int k = 0; k < dimSubstring && ind < dimS; k++)
			{
				if(substring[k] == s[ind]) ind++;
			}
			mx = max(mx, ind);
		}
	}

	int rem = dimSubsequence-mx;

	int tot = dimSubstring+rem;

	cout << tot << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
