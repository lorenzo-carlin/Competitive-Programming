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
	vector<int> v(n/4);

	auto scan = [&] () -> int
	{
		char buf, fst, snd;
		cin >> buf >> fst >> snd >> buf;
		if(fst == '+') return 0;
		else return 1;
	};

	for(int i = 0; i < n/4; ++i) v[i] = scan();

	int zero = 0, uno = 0;
	for(int i = 0; i < n/4; ++i)
	{
		if(v[i] == 0) zero++;
		else uno++;
	}

	cout << min(zero, uno) << "\n";
}
