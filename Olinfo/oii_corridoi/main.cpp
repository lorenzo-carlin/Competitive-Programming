#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

vector<ll> shorten(int n, int m, int q, vector<ll> k, vector<int> a, vector<int> b, vector<int> c)
{
    if(q != 1)
    {
        vector<vector<array<int,2>>> adj(n);
        for(int i = 0; i < m; i++)
        {
            adj[a[i]].push_back({b[i], c[i]});
            adj[b[i]].push_back({a[i], c[i]});
        }

        auto distances = [&] (int v) -> vector<ll>
        {
            vector<ll> dist(n, INF);
            priority_queue<array<ll,2>> pq;

            pq.push({0, v});
            while(!pq.empty())
            {
                ll d = -pq.top()[0];
                int u = pq.top()[1];
                pq.pop();

                if(d >= dist[u]) continue;
                dist[u] = d;

                for(auto nxt: adj[u])
                {
                    if(d+nxt[1] < dist[nxt[0]])
                    {
                        pq.push({-(d+nxt[1]), nxt[0]});
                    }
                }
            }

            return dist;
        };

        vector<ll> dist0 = distances(0);
        vector<ll> dist1 = distances(1);
        vector<ll> dist2 = distances(2);

        vector<ll> full(n);
        for(int i = 0; i < n; i++)
            full[i] = dist0[i] + 2*dist1[i] + dist2[i];
        vector<ll> change(n);
        for(int i = 0; i < n; i++)
            change[i] = dist1[i];

        auto f = [&] (int c, ll t) -> ll
        {
            if(t <= change[c])
                return full[c] -2*t;
            return max(0LL, full[c] -2*change[c] - (t-change[c]));
        };

        priority_queue<array<ll,2>> pq;
        for(int i = 0; i < n; i++)
            pq.push({-f(i, 0), i});

        vector<array<ll,2>> queries(q);
        for(int i = 0; i < q; i++)
        {
            queries[i] = {k[i], i};
        }

        sort(begin(queries), end(queries));

        vector<ll> ans(q);
        int mx_idx = pq.top()[1];
        for(int i = 0; i < q; i++)
        {
            while(!pq.empty() && queries[i][0] > change[pq.top()[1]])
                pq.pop();
            if(!pq.empty() && f(pq.top()[1], queries[i][0]) < f(mx_idx, queries[i][0]))
            {
                mx_idx = pq.top()[1];
            }
            ans[queries[i][1]] = f(mx_idx, queries[i][0]);
        }

        return ans;
    }

    vector<vector<pair<int,int>>> adj(n);
	for(int i = 0; i < m; ++i)
	{
		adj[a[i]].push_back({b[i], c[i]});
		adj[b[i]].push_back({a[i], c[i]});
	}

	vector<ll> distA(n, INF), distB(n, INF), distC(n, INF);
	priority_queue<pair<ll,int>> pq;

	pq.push({0, 0});
	while(!pq.empty())
	{
		ll d = -pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if(distA[v] <= d) continue;
		distA[v] = d;

		for(auto u: adj[v])
		{
			ll newd = d+u.second;
			pq.push({-newd,u.first});
		}
	}

	pq.push({0, 1});
	while(!pq.empty())
	{
		ll d = -pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if(distB[v] <= d) continue;
		distB[v] = d;

		for(auto u: adj[v])
		{
			ll newd = d+u.second;
			pq.push({-newd,u.first});
		}
	}

	pq.push({0, 2});
	while(!pq.empty())
	{
		ll d = -pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if(distC[v] <= d) continue;
		distC[v] = d;

		for(auto u: adj[v])
		{
			ll newd = d+u.second;
			pq.push({-newd,u.first});
		}
	}

	ll mn = INF;
	for(int i = 0; i < n; ++i)
	{
		ll distAi = distA[i];
		ll distBi = distB[i];
		ll distCi = distC[i];

		ll tot = distAi+distBi+distBi+distCi;
		ll rem = k[0];
		tot -= 2*min(rem, distBi);
		rem -= min(rem, distBi);
		tot -= min(rem, tot);

		mn = min(mn, tot);
	}

	return {mn};
}
