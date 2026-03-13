#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r; cin >> n >> r;
	map<string,vector<string>> inviati, ricevuti;

	string a, b;
	for(int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		inviati[a].push_back(b);
		ricevuti[b].push_back(a);
	}

	for(int i = 0; i < r; ++i)
	{
		cin >> a >> b;
		if(b == "INVIATI")
		{
			cout << inviati[a].size() << " ";
			for(auto el: inviati[a]) cout << el << " ";
			cout << "\n";
		} else
		{
			cout << ricevuti[a].size() << " ";
			for(auto el: ricevuti[a]) cout << el << " ";
			cout << "\n";
		}
	}
}
