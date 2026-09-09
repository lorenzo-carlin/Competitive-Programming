#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	string s;
	cin >> s;

	int ind = 0;
	string a = "TuNZ", b = "PaH";
	string ans;
	
	bool word = false;
	while(ind < n)
	{
		if(n-ind >= 3 && b == s.substr(ind, 3))
		{
			word = false;
			ind += 3;
		} else if(n-ind >= 4 && a == s.substr(ind, 4))
		{
			word = false;
			ind += 4;
		} else
		{
			if(!word)
			{
				ans += ' ';
				word = true;
			}
			ans += s[ind];
			ind++;
		}
	}

	ans.erase(ans.begin());
	cout << ans << "\n";
}
