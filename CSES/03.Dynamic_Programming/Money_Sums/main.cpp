#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	sort(begin(v), end(v));

	set<int> s;
	for(int i = 0; i < n; ++i)
	{
		vector<int> additional;
		additional.push_back(v[i]);
		for(int el: s)
		{
			additional.push_back(el+v[i]);
		}
		for(int el: additional)
		{
			s.insert(el);
		}
	}

	cout << s.size() << "\n";
	for(int el: s) cout << el << " ";
	cout << "\n";
}
