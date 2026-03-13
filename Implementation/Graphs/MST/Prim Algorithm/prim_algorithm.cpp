#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int ind = 0, n_raggiunti = 1, tot = 0;
    vector<bool> preso(n, false);
    vector<pair<int,int>> archi_sol;
    priority_queue<pair<int,pair<int,int>>> pq;

    while(n_raggiunti < n)
    {
        preso[ind] = true;
        for(auto el: adj[ind])
        {
            int q = el.first;
            int w = el.second;
            if(!preso[q]) pq.push({-w, {ind, q}});
        }

        pair<int,pair<int,int>> x;
        do
        {
            x = pq.top();
            pq.pop();
        } while(preso[x.second.second]);

        archi_sol.push_back(x.second);
        tot -= x.first;
        n_raggiunti++;
        ind = x.second.second;
    }

    cout << tot << "\n";
}