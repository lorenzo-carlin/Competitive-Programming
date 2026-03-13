#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int BLOCK = 333;

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0, p; i < n; ++i)
	{
		cin >> p; p--;
		a[i] = p;
	}

	int q; cin >> q;
	vector<array<int,3>> queries(q);
	for(int i = 0, x, y; i < q; ++i)
	{
		cin >> x >> y; x--; y--;
		queries[i] = {x, y, i};
	}

	sort(begin(queries), end(queries), [&](array<int,3> x, array<int,3> y)
	{
		if(x[0]/BLOCK != y[0]/BLOCK) return x[0] < y[0];
		else return x[1] < y[1];
	});

	int cl = 0, cr = -1;
	vector<int> occ(n, 0);
	int ans = 0;
	vector<int> sol(q);
	for(auto [l, r, ind]: queries)
	{
		while(r < cr) // riduzione a dx
		{
			occ[a[cr]]--;
			if(occ[a[cr]] & 1) ans--;
			cr--;
		}
		while(r > cr) // allargamento a dx
		{
			cr++;
			occ[a[cr]]++;
			if(!(occ[a[cr]] & 1)) ans++;
		}
		while(l < cl) // allargamento a sx
		{
			cl--;
			occ[a[cl]]++;
			if(!(occ[a[cl]] & 1)) ans++;
		}
		while(l > cl) // riduzione a sx
		{
			occ[a[cl]]--;
			if(occ[a[cl]] & 1) ans--;
			cl++;
		}
		sol[ind] = ans;
	}

	for(int i = 0; i < q; ++i)
	{
		cout << sol[i] << "\n";
	}
}


