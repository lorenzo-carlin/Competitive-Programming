#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // input
    int n,m;
    cin>>n>>m;

    int altezza[n];
    for (int i=0;i<n;i++) {
        cin>>altezza[i];
    }

    vector<vector<int>> adj(n);
    vector<bool> vis(n,false);
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int nodo=0, ultimo = -1;
    while(!vis[nodo])
    {
        vis[nodo] = true;
        int minn = 1000001;
        int pos = -1;
        // scelgo il prossimo incrocio
        for(int i = 0; i < adj[nodo].size(); i++)
        {
            int v = adj[nodo][i];
            if(altezza[v] < minn && v != ultimo)
            {
                minn = altezza[v];
                pos = v;
            }
        }
        if(pos == -1)
        {
            // sono costretto ad un inversione ad U, mi fermo prima
            break;
        } else if(vis[pos]==true)
        {
            // vado nel nodo ma questo è già visitato, quindi mi fermo su quel nodo
            nodo = pos;
            break;
        }
        ultimo = nodo;
        nodo = pos;

    }

    cout << nodo << "\n";
    /*


    while (adj[nodo].size()>1) {
        int min=1000001;
        for (int i=0;i<adj[nodo].size();i++) {
            if (altezza[adj[nodo][i]]<min && !vis[adj[nodo][i]]) {
                min=altezza[adj[nodo][i]];
                pos=adj[nodo][i];
            }
        }
        if (min<1000001) {
            ultimo=nodo;
            nodo=pos;
            vis[nodo]=true;
        }else {
            break;
        }
    }

    cout << nodo;
    if (adj[nodo].size()==1) {
        cout<<nodo;
    }else {
        int min=1000001;
        for (int i=0;i<adj[nodo].size();i++) {
            if (altezza[adj[nodo][i]]<min && ultimo!=adj[nodo][i]) {
                min=altezza[adj[nodo][i]];
                pos=adj[nodo][i];
            }
        }
        cout<<pos;
    }
    */
    return 0;
}