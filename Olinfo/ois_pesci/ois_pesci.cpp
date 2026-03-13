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
	stack<pair<int,int>> s;
	for(int i = 0, a, b; i < n; ++i)
	{
		cin >> a >> b;

		if(s.empty() || s.top().first == a)
		{
			s.push({a, b});
			continue;
		}

		while(!s.empty() && a == 1 && s.top().first == 0 && s.top().second < b)
		{
			s.pop();
		}

		if(!s.empty() && a == 1 && s.top().first == 0 && s.top().second > b) continue;

		s.push({a, b});
	}

	cout << s.size() << "\n";
}
