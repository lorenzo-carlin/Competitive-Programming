/*
 * Sparse Table
 * Supports efficient static range queries, typically in O(log n) preprocessing
 * and O(1) query time for idempotent operations such as range minimum.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Sparse_Table
{
    int n, k;
    vector<int> log;
    vector<vector<int>> t;

    Sparse_Table() {}

    Sparse_Table(vector<int> v) : n(v.size())
    {
        log.resize(n+1, 0);
        for(int i = 2; i <= n; i++)
            log[i] = log[i/2]+1;
        k = log[n];
        t.resize(k+1, vector<int> (n));

        for(int i = 0; i < n; i++)
            t[0][i] = v[i];
        for(int i = 1; i <= k; i++)
            for(int j = 0; j + (1 << i) - 1 < n; j++)
                t[i][j] = min(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }

    int query(int l, int r)
    {
        int d = log[r-l+1];
        return min(t[d][l], t[d][r-(1<<d)+1]);
    }
};

int main()
{
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    Sparse_Table st = Sparse_Table(v);

    while(q--)
    {
        int a, b; cin >> a >> b;
        cout << st.query(a, b) << "\n";
    }
}
