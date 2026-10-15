#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    vector<int> deg(n, 0);    
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);

        deg[a]++;
        deg[b]++;
    }

    // caso "Brain Melt"
    bool brainMelt = false;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            brainMelt = true;
        }
    }

    if(brainMelt) {
        cout << "Brain Melt\n";
        return;
    }

    // caso 2
    bool two = false;

    if(n == 2 && deg[0] == 1 && deg[1] == 1) {
        two = true;
    }

    int degOne = 0, degCenter = 0;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 1) {
            degOne++;
        }
        if(deg[i] == n-1) {
            degCenter++;
        }
    }
    if(degOne == n-1 && degCenter == 1) {
        two = true;
    }

    if(two) {
        cout << 2 << "\n";
        return;
    }

    cout << "Many\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}