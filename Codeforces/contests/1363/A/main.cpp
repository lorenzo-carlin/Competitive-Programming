#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    int pari = 0, dispari = 0;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if(a & 1) dispari++;
        else pari++;
    }

    int mn = max(1, x - pari);
    int mx = min(x, dispari);

    if(mn % 2 == 0) mn++;

    cout << (mn <= mx ? "Yes\n" : "No\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();
}