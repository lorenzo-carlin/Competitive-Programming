#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment {
    int n;
    vector<pair<ll,ll>> t;

    Segment() {}

    Segment(int _n) {
        for(n = 1; n <= _n; n <<= 1);
        t.resize(2*n, {0, 0ll});
    }

    pair<ll,ll> merge(pair<ll,ll> a, pair<ll,ll> b) {
        pair<ll,ll> c;
        c.first = a.first + b.first;
        c.second = a.second + b.second;
        return c;
    }

    void update(int i, int tl, int tr, ll v, int p) {
        if(p < tl || tr < p) return;
        if(tl == p && tr == p) {
            t[i].first++;
            t[i].second += v;
        } else {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, v, p);
            update(2*i+1, tm+1, tr, v, p);
            t[i] = merge(t[2*i], t[2*i+1]);
        }
    }

    void update(ll v, int p) {
        update(1, 0, n-1, v, p);
    }

    pair<ll,ll> query(int i, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return {0, 0ll};
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return merge(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
    }

    pair<ll,ll> query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void clear() {
        t.assign(2*n, {0, 0ll});
    }
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(ll &i: a) cin >> i;

    ll initialMovementDistance = 0;
    Segment seg = Segment(n);
    vector<ll> movementDistanceTopBlock(n);
    for(int i = n-1; i >= 0; i--) {
        auto [quantity, occupiedCells] = seg.query(1, a[i]);
        ll totalCells = a[i] * quantity;
        initialMovementDistance += (totalCells - occupiedCells);
        movementDistanceTopBlock[i] = (quantity - seg.query(a[i], a[i]).first);
        seg.update(a[i], a[i]);
    }

    seg.clear();

    ll maxDelta = 0;
    for(int i = 0; i < n; i++) {
        ll currentDelta = 0;
        currentDelta += seg.query(a[i], n).first;
        currentDelta -= movementDistanceTopBlock[i];
        maxDelta = max(maxDelta, currentDelta);
        seg.update(a[i], a[i]);
    }

    initialMovementDistance += maxDelta;
    cout << initialMovementDistance << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}