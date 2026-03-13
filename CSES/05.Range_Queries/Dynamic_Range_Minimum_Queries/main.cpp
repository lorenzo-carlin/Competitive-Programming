#include <bits/stdc++.h>
using namespace std;

const int MAX = 8*1e5+1;
vector<int> tree (MAX, 1e9);
vector<int> v;

void build(int ind, int st, int fn)
{
    if(st == fn)
    {
        tree[ind] = v[st];
    } else
    {
        int med = (st+fn)/2;
        build(ind*2, st, med);
        build(ind*2+1, med+1, fn);
        tree[ind] = min(tree[ind*2], tree[ind*2+1]);
    }
}

int query(int ind, int st, int fn, int l, int r)
{
    if(l > r) return 1e9;
    if(l == st && r == fn) return tree[ind];
    int med = (st+fn)/2;
    return min(query(ind*2, st, med, l, min(r, med)), query(ind*2+1, med+1, fn, max(l, med+1), r));
}

void update(int ind, int st, int fn, int pos, int val)
{
    if(st == fn)
    {
        tree[ind] = val;
    } else
    {
        int med = (st+fn)/2;
        if(pos <= med)
        {
            update(ind*2, st, med, pos, val);
        } else
        {
            update(ind*2+1, med+1, fn, pos, val);
        }
        tree[ind] = min(tree[ind*2], tree[ind*2+1]);
    }
}

int main()
{
    int n, q; cin >> n >> q;
    v.clear(); v.push_back(1e9);
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