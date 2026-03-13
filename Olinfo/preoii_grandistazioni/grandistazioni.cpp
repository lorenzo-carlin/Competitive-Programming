#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

ll viaggia(int n, int m, vector<int> a, vector<int> b, vector<int> t, vector<int> v, vector<int> w)
{
    // O(M)
    // lista di adiacenza con: {indice tratta}
    vector<vector<int>> adjR(n);
    for(int i = 0; i < m; ++i)
    {
        adjR[b[i]].push_back(i);
    }

    // O((N+M)logN)
    vector<ll> dist(n, INF);
    // successivo: {nodo a cui va, tratta che segue}
    vector<pair<int,int>> succ(n, {-1, -1});
    // pq: {-dist, tratta fatta per arrivarci}
    priority_queue<pair<ll,int>> pq;
    dist[n-1] = 0;
    succ[n-1] = {n-1, -1};
    for(int tratta: adjR[n-1])
    {
        pq.push({-t[tratta], tratta});
    }
    while(!pq.empty())
    {
        ll d       = -pq.top().first;
        int tratta =  pq.top().second;
        pq.pop();

        int curr = a[tratta];
        int prec = b[tratta];

        if(d >= dist[curr]) continue;
        dist[curr] = d;
        succ[curr].first = prec;
        succ[curr].second = tratta;

        for(int newTr: adjR[curr])
        {
            ll newD = d + t[newTr];
            if(newD < dist[a[newTr]])
            {
                pq.push({-newD, newTr});
            }
        }
    }

    // simuliamo
    vector<bool> gia_sbagliato(n, false);
    for(int i = 0; i < n; ++i)
    {
        if(v[i] == -1)
        {
            gia_sbagliato[i] = true;
        }
    }

    ll ans = 0;
    int curr = 0;
    while(curr != n-1)
    {
        if(gia_sbagliato[curr])
        {
            int prox = succ[curr].first;
            ans += t[succ[curr].second];
            curr = prox;
        } else
        {
            gia_sbagliato[curr] = true;
            int prox = v[curr];
            ans += w[curr];
            curr = prox;
        }
    }

    return ans;
}