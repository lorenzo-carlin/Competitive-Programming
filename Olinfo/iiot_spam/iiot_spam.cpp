#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int B, G, E;
	cin >> B;
	set<string> bad;
	for(int i = 0; i < B; ++i)
	{
		string s; cin >> s;
		bad.insert(s);
	}
	cin >> G;
	set<string> good;
	for(int i = 0; i < G; ++i)
	{
		string s; cin >> s;
		good.insert(s);
	}

	cin >> E;
	int spam = 0, legit = 0;
	while(E--)
	{
		int N; cin >> N;
		bool sp = false, leg = false;
		for(int i = 0; i < N; ++i)
		{
			string s; cin >> s;
			if(bad.count(s)) sp = true;
			if(good.count(s)) leg = true;
		}
		if(sp && leg) continue;
		if(sp) spam++;
		if(leg) legit++;
	}

	cout << spam << " " << legit << "\n";
}
