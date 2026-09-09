#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<string> v(n);
	for(auto &i: v) cin >> i;

	int toggle = 0;
	bool bold = false, italic = false;

	for(int i = 0; i < n; ++i)
	{
		if((v[i] == "i" || v[i] == "I") && !italic)
		{
			italic = true;
			toggle++;
		}
		if((v[i] == "N" || v[i] == "I") && !bold)
		{
			bold = true;
			toggle++;
		}
		if(v[i] == "n" || v[i] == "i") bold = false;
		if(v[i] == "n" || v[i] == "N") italic = false;
	}

	cout << toggle << "\n";
}
