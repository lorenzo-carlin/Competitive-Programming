#include <bits/stdc++.h>
using namespace std;

vector<int> pools;
map<int,set<int>> padri;

float P(int nodo, vector<vector<int>> &adj, vector<float> &prob)
{
    if(prob[nodo] != 0.0)
    {
        return prob[nodo];
    }

    float pr = 0.0;
    for(auto padre:padri[nodo])
    {
        pr += (P(padre, adj, prob)/adj[padre].size());
    }
    prob[nodo] = pr;
    return pr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n, m, p; cin >> n >> m >> p;
    for(int i = 0; i < p; ++i)
    {
        pools.push_back(n-(i+1));
    }

    vector<vector<int>> adj(n);
    vector<float> prob(n, 0.0);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        padri[b].insert(a);
    }

    // risoluzione
    prob[0] = 1.0;
    float mx = 0.0;
    int mx_ind = -1;

    for(auto el:pools)
    {
        float tmp = P(el, adj, prob);
        if(tmp > mx)
        {
            mx = tmp;
            mx_ind = el;
        }
    }

    cout << mx_ind << "\n";
    
    /*
    for(int i = 0; i < n; ++i)
    {
        cout << prob[i] << "\n";
    }
    */
}