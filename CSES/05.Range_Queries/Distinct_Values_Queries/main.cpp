#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int BLOCK = 512;

struct MO
{
	int n, cnt;
	vector<int> frq;

	MO(int _n) : n(_n), cnt(0), frq(n, 0) {}

	void add(int v)
	{
		if(frq[v] == 0)
		{
			cnt++;
		}
		frq[v]++;
	}

	void erase(int v)
	{
		if(frq[v] == 1)
		{
			cnt--;
		}
		frq[v]--;
	}

	int get_ans()
	{
		return cnt;
	}
};

int main()
{
	// read input
	int n, q; cin >> n >> q;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	// index-compression
	auto zip = v;
	sort(begin(zip), end(zip));
	zip.erase(unique(begin(zip),end(zip)),end(zip));
	for(int &i: v)
	{
		i = lower_bound(begin(zip), end(zip), i) - begin(zip);
	}

	// read and sort queries
	vector<array<int,3>> queries(q);
	for(int i = 0, a, b; i < q; ++i)
	{
		cin >> a >> b; --a; --b;
		queries[i] = {a, b, i};
	}

	auto comp = [&](array<int,3> a, array<int,3> b)
	{
		if(a[0] / BLOCK != b[0] / BLOCK)
		{
			return a[0] < b[0];
		} else
		{
			return a[1] < b[1];
		}
	};

	sort(begin(queries), end(queries), comp);

	MO m = MO(n);

	vector<int> ans(q);

	int l = 0, r = -1;
	for(auto [a, b, i]: queries)
	{
		while(r < b) {r++; m.add(v[r]);}
		while(r > b) {m.erase(v[r]); r--;}
		while(l < a) {m.erase(v[l]); l++;}
		while(l > a) {l--; m.add(v[l]);}
		ans[i] = m.get_ans();
	}

	for(int i = 0; i < q; ++i)
	{
		cout << ans[i] << "\n";
	}
}
