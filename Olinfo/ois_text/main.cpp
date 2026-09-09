#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	int line = 0;
	while(n--)
	{
		string s; cin >> s;
		if(line+s.size() <= k)
		{
			cout << s << " ";
			line += (s.size()+1);
		} else
		{
			cout << "\n" << s << " ";
			line = s.size()+1;
		}
	}
	cout << "\n";
}
