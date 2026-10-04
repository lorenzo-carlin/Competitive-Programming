#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b)/gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;

    vector<int> startingDeck(n);
    iota(begin(startingDeck), end(startingDeck), 0);

    vector<vector<int>> piles(k);
    vector<int> newDeck(n);
    for(int i = 0; i < n; i++) {
        piles[i % k].push_back(startingDeck[i]);
    }
    
    int currentPile = 0;
    int count = 0;
    while(count < n) {
        if(piles[currentPile].empty()) {
            currentPile++;
        }

        newDeck[count] = piles[currentPile].back();
        piles[currentPile].pop_back();

        count++;
    }

    vector<int> idx(n);
    for(int i = 0; i < n; i++) {
        idx[newDeck[i]] = i;
    }

    // for(int el: newDeck) cout << el << " ";
    // cout << "\n";


    // Obiettivo: ora trovo i cicli e la loro durata
    vector<bool> vis(n, false);
    ll ans = 1;
    vector<int> cycle;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        cycle.clear();

        int curr = idx[i];
        vis[i] = true;
        cycle.push_back(i);

        while(!vis[curr]) {
            vis[curr] = true;
            cycle.push_back(curr);

            curr = idx[curr];
        }

        int cycleSize = cycle.size();
        ans = lcm(ans, cycleSize);

        // cout << "cycle: ";
        // for(int el: cycle) cout << el << " ";
        // cout << "\n";
    }

    cout << ans << "\n";
}