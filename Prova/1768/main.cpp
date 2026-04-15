#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	multiset<int> ms;
	for(int i = 1; i <= n; ++i)
	{
		ms.insert(i);
		ms.insert(i);
	}

	vector<int> a(n);
	for(auto &i: a) cin >> i;

	vector<int> occ(n, 0);
	for(int i = 0; i < n; ++i)
	{
		occ[a[i]-1]++;
		if(occ[a[i]-1] > 2)
		{
			cout << "NO\n";
			return;
		}
	}
	vector<int> c = a;
	sort(begin(c), end(c));
	for(int i = 0; i < n; ++i)
	{
		if(c[i] < i+1)
		{
			cout << "NO\n";
			return;
		}
	}

	priority_queue<pair<int,int>> pq;
	for(int i = 0; i < n; ++i)
	{
		pq.push({a[i], i});
		ms.erase(ms.find(a[i]));
	}

	vector<int> p(n), q(n);
	set<int> s;
	while(!pq.empty())
	{
		int val = pq.top().first;
		int ind = pq.top().second;
		pq.pop();

		if(s.count(val)) // val c'è già in p[]
		{
			q[ind] = val;
			auto it = ms.upper_bound(val);
			if(it == ms.begin())
			{
				cout << "NO\n";
				return;
			}
			it--;
			p[ind] = *it;
			s.insert(*it);
			ms.erase(it);
		} else
		{
			p[ind] = val;
			s.insert(val);
			auto it = ms.upper_bound(val);
			if(it == ms.begin())
			{
				cout << "NO\n";
				return;
			}
			it--;
			q[ind] = *it;
			ms.erase(it);
		}
	}

	cout << "YES\n";
	for(int el: p) cout << el << " ";
	cout << "\n";
	for(int el: q) cout << el << " ";
	cout << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
