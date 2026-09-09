#include <bits/stdc++.h>
using namespace std;

int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    int n,m;
    in>>n>>m;
    int altezza[n];
    for (int i=0;i<n;i++) {
        in>>altezza[i];
    }
    vector<vector<int>> adj(n);
    vector<bool> vis(n,false);
    for (int i=0;i<m;i++) {
        int a,b;
        in>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // scelgo il primo incrocio
    int nodo=0, ultimo = -1;
    while (!vis[nodo]) {
        int pos = -1;
        vis[nodo]=true;
        int min=1000001;
        // cerco il nodo con altitudine minore che non sia quello da cui provengo
        for (int i=0;i<adj[nodo].size();i++) {
            if (altezza[adj[nodo][i]]<min && adj[nodo][i] != ultimo) {
                min=altezza[adj[nodo][i]];
                pos=adj[nodo][i];
            }
        }
        if(pos == -1)
        {
            // se pos è rimasto = 1, vuol dire che adj[node][i]==1
            // quindi sono costretto a fare un'inversione ad U
            // esco dal ciclo senza fare nodo = pos
            break;
        } else if(vis[pos])
        {
            // se ho già visitato il nodo in cui devo andare ora,
            // vado in quel nodo ed esco dal ciclo
            nodo = pos;
            break;
        }
        ultimo = nodo;
        nodo = pos;
    }
    out << nodo;
    return 0;
}
