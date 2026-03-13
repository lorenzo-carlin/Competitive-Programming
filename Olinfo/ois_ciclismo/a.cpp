#include <bits/stdc++.h>
using namespace std;

int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int n,m,ultimo=0;
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
    int nodo=0;
    int pin=1000001;
    int pos;
    for (int i=0;i<adj[nodo].size();i++) {
        if (altezza[adj[nodo][i]]<pin) {
            pin=altezza[adj[nodo][i]];
            pos=adj[nodo][i];
        }
    }
    vis[0]=true; 
    nodo=pos;
    while (adj[nodo].size()>1) {
        int min=1000001;
        for (int i=0;i<adj[nodo].size();i++) {
            if (altezza[adj[nodo][i]]<min && !vis[adj[nodo][i]]) {
                min=altezza[adj[nodo][i]];
                pos=adj[nodo][i];
            }
        }
        if (min<1000001) {
            vis[nodo]=true;    
            ultimo=nodo;
            nodo=pos;
        }else {
            break;
        }
    }
    if (adj[nodo].size()==1) {
        out<<nodo;
    }else {
        int min=1000001;
        for (int i=0;i<adj[nodo].size();i++) {
            if (altezza[adj[nodo][i]]<min && ultimo!=adj[nodo][i]) {
                min=altezza[adj[nodo][i]];
                pos=adj[nodo][i];
            }
        }
        out<<pos;
    }
    return 0;
}