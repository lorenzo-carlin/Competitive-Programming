#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2097152 + 5;
constexpr ll INF = 1e18;

vector<ll> dist(MAXN, INF);

struct myds
{
	int n, vuote;
	vector<int> v;
	set<pair<ll,int>> s;
	map<int,queue<int>> q;

	myds() {}
	myds(vector<int> a)
	{
		n = a.size();
		v = a;
		vuote = n;
	}

	bool check()
	{
		if(vuote == n) return false;
		else return true;
	}

	void add(int u, int w)
	{
		if(q[w].empty())
		{
			vuote--;
			s.insert({dist[u], w});
		}
		q[w].push(u);
	}

	void print()
	{
		for(int i = 0; i < n; ++i)
		{
			cout << v[i] << ": ";
			if(q[v[i]].empty()) cout << "empty";
			else cout << q[v[i]].front();
			cout << "\n";
		}
	}

	int query()
	{
		int idx = (*s.begin()).second;
		s.erase(s.begin());
		int ans = q[idx].front();
		q[idx].pop();
		if(q[idx].empty()) vuote++;
		else s.insert({dist[q[idx].front()], idx});
		return ans;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q; cin >> n >> m >> q;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];
	int tmp = a.front();

	vector<int> v;
	for(auto el: a) v.push_back(el);
	for(auto el: b) v.push_back(el);
	sort(begin(v), end(v));
	v.erase(unique(begin(v), end(v)), end(v));

	myds Q = myds(v);

	for(int i = 0, k; i < m; ++i)
	{
		cin >> k;
		int code = 0;
		for(int j = 0, p; j < k; ++j)
		{
			cin >> p;
			code += (1 << p);
		}
		Q.add(code, tmp);
		dist[code] = 0;
	}

	while(Q.check())
	{
		int v = Q.query();
		for(int i = 0; i < n; i++)
		{
			if(v & (1 << i))
			{
				// posso toglierlo
				int nxt = v - (1 << i);
				if(dist[nxt] > dist[v]+b[i])
				{
					dist[nxt] = dist[v]+b[i];
					Q.add(nxt, b[i]);
				}
			} else
			{
				// posso aggiungerlo
				int nxt = v + (1 << i);
				if(dist[nxt] > dist[v]+a[i])
				{
					dist[nxt] = dist[v]+a[i];
					Q.add(nxt, a[i]);
				}
			}
		}
	}

	for(int i = 0; i < q; ++i)
	{
		int k, code = 0;
		cin >> k;
		for(int j = 0, p; j < k; ++j)
		{
			cin >> p;
			code += (1 << p);
		}
		cout << dist[code] << "\n";
	}
}		
