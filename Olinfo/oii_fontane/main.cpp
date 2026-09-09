#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;
	vector<pair<int,int>> v(n+1);
	for(int i = 0; i < n+1; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	map<int,set<int>> stessa_ascissa, stessa_ordinata;
	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		stessa_ascissa[a].insert(b);
		stessa_ordinata[b].insert(a);
	}

	int maxx = 0;

	pair<int,int> ultimo;
	int rimanente = 0, tot;
	for(int i = 0; i < n; ++i)
	{
		ultimo = v[i];

		if(v[i].f == v[i+1].f)
		{
			// stessa_ascissa
			if(v[i].s < v[i+1].s)
			{
				// va dal basso verso l'alto
				auto it = stessa_ascissa[v[i].f].upper_bound(v[i].s);
				while(it != stessa_ascissa[v[i].f].end() && *it <= v[i+1].s)
				{
					tot = rimanente + (*it - ultimo.s);
					// cout << tot << "\t";
					maxx = max(maxx, tot);
					rimanente = 0;
					ultimo = {v[i].f, *it};
					it++;
				}
				rimanente += (v[i+1].s - ultimo.s);
			} else
			{
				// va dall'alto verso il basso
				auto it = stessa_ascissa[v[i].f].upper_bound(v[i].s);
				while(it != stessa_ascissa[v[i].f].begin() && *(--it) >= v[i+1].s)
				{
					tot = rimanente + (ultimo.s - *it);
					// cout << tot << "\t";
					maxx = max(maxx, tot);
					rimanente = 0;
					ultimo = {v[i].f, *it};
				}
				rimanente += (ultimo.s - v[i+1].s);
			}
		} else if(v[i].s == v[i+1].s)
		{
			// stessa ordinata
			if(v[i].f < v[i+1].f)
			{
				// va da sx a dx
				auto it = stessa_ordinata[v[i].s].upper_bound(v[i].f);
				while(it != stessa_ordinata[v[i].s].end() && *it <= v[i+1].f)
				{
					tot = rimanente + (*it - ultimo.f);
					// cout << tot << "\t";
					maxx = max(maxx, tot);
					rimanente = 0;
					ultimo = {*it, v[i].s};
					it++;
				}
				rimanente += (v[i+1].f - ultimo.f);
			} else
			{
				// va da dx a sx
				auto it = stessa_ordinata[v[i].s].upper_bound(v[i].f);
				while(it != stessa_ordinata[v[i].s].begin() && *(--it) >= v[i+1].f)
				{
					tot = rimanente + (ultimo.f - *it);
					// cout << tot << "\t";
					maxx = max(maxx, tot);
					rimanente = 0;
					ultimo = {*it, v[i].s};
				}
				rimanente += (ultimo.f - v[i+1].f);
			}
		}
	//	cerr << i << ": " << rimanente << "\n";
	}

	cout << maxx-100 << "\n";
}
