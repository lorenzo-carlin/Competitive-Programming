#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> z_algorithm(string s)
{
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for(int i = 1; i < n; ++i)
	{
		if(i < r) z[i] = min(r-i, z[i-l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] ++;
		if(i + z[i] > r)
		{
			l = i;
			r = i + z[i];
		}
	}

	return z;
}

int main()
{
	string s; cin >> s;

	vector<int> z = z_algorithm(s);
	vector<int> sol;

	for(int i = 0; i < s.size(); ++i)
	{
		if(z[i] == (s.size()-i)) sol.push_back(z[i]);
	}

	reverse(begin(sol), end(sol));

	for(int el: sol) cout << el << " ";
	cout << "\n";
}
