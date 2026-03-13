#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    int n;
    vector<int> t;

    Segment(int _n, vector<int> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n, 0);
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr) t[i] += v;
        else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = t[2*i] + t[2*i+1];
        }
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
    }

    int query(int i, int tl, int tr, int l, int r)
    {
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return query(2*i, tl, tm, l, r) + query(2*i+1, tm+1, tr, l, r);
    }

    int query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }
};

int comp(int n, vector<int> &idx)
{
    return lower_bound(begin(idx), end(idx), n) - begin(idx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;

    vector<int> idx, val(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> val[i];
        idx.push_back(val[i]);
    }
    vector<array<int, 3>> queries(q);
    for(int i = 0, a, b; i < q; ++i)
    {
        char c; cin >> c;
        cin >> a >> b;
        if(c == '!')
        {
            idx.push_back(b);
            queries[i] = {1, a, b};
        } else
        {
            idx.push_back(a);
            idx.push_back(b);
            queries[i] = {0, a, b};
        }
    }

    sort(begin(idx), end(idx));
    idx.erase(unique(begin(idx), end(idx)), end(idx));

    for(auto &i: val) i = comp(i, idx);
    for(int i = 0; i < q; ++i)
    {
        if(queries[i][0] == 1) queries[i][2] = comp(queries[i][2], idx);
        else
        {
            queries[i][1] = comp(queries[i][1], idx);
            queries[i][2] = comp(queries[i][2], idx);
        }
    }

    Segment st = Segment(idx.size(), idx);
    for(auto el: val) st.update(el, 1);

    for(auto el: queries)
    {
        if(el[0] == 1)
        {
            st.update(val[el[1]-1], -1);
            val[el[1]-1] = el[2];
            st.update(val[el[1]-1], 1);
        } else
        {
            cout << st.query(el[1], el[2]) << "\n";
        }
    }

}