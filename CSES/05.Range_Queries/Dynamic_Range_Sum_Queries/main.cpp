#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 8*1e5+1;
vector<ll> tree (MAX, 0);
vector<ll> v;

void build(int ind, int st, int fn)
{
    if(st == fn)
    {
        tree[ind] = v[st];
    } else
    {
        int med = (st + fn) / 2;
        build(ind*2, st, med);
        build(ind*2+1, med+1, fn);
        tree[ind] = tree[ind*2] + tree[ind*2+1];
    }
}

void update(int ind, int st, int fn, int pos, int val)
{
    if(st == fn)
    {
        tree[ind] = val;
    } else
    {
        int med = (st + fn) / 2;
        if(pos <= med)
        {
            update(ind*2, st, med, pos, val);
        } else
        {
            update(ind*2+1, med+1, fn, pos, val);
        }
        tree[ind] = tree[ind*2] + tree[ind*2+1];
    }
}

ll query(int ind, int st, int fn, int l, int r)
{
    if(l > r) return 0;
    if(l == st && r == fn) return tree[ind];
    int med = (st + fn) / 2;
    return (ll) query(ind*2, st, med, l, min(med,r)) + query(ind*2+1, med+1, fn, max(med+1,l), r);
}

int main()
{
    v.clear();
    v.push_back(0);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    build(1, 1, n);
    for(int i = 0; i < q; ++i)
    {
        int b, c, d; cin >> b >> c >> d;
        if(b == 1)
        {
            update(1, 1, n, c, d);
        } else
        {
            cout << query(1, 1, n, c, d) << "\n";
        }
    }
}