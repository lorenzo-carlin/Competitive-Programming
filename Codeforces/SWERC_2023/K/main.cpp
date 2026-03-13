#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int n;
    vector<int> t;

    Segment(int _n) {
        for (n = 1; n < _n; n <<= 1);
        t.assign(2 * n, 0);
        for (int i = n; i < n + _n; ++i) t[i] = 1;
        for (int i = n - 1; i > 0; --i) t[i] = t[2 * i] + t[2 * i + 1];
    }

    void update(int p, int v) {
        int i = p + n;
        t[i] = v;
        for (i >>= 1; i; i >>= 1)
            t[i] = t[2 * i] + t[2 * i + 1];
    }

    int query(int k) {
        int i = 1;
        while (i < n) {
            if (t[2 * i] >= k) i = 2 * i;
            else k -= t[2 * i], i = 2 * i + 1;
        }
        return i - n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;
    vector<int> a(m / 2), b(m / 2);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    Segment seg(m);
    vector<int> A, B;

    for (int i = 0; i < m; i++) {
        if (i & 1) {
            int x = b[i / 2];
            int pos = seg.query(x);
            B.push_back(pos);
            seg.update(pos, 0);
        } else {
            int x = a[i / 2];
            int pos = seg.query(x);
            A.push_back(pos);
            seg.update(pos, 0);
        }
    }

    for (int el : A) cout << el + 1 << " ";
    cout << "\n";
    for (int el : B) cout << el + 1 << " ";
    cout << "\n";
}

