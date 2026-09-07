/*
 * Segment Tree: sum query
 * Iterative implementation
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    int n;
    vector<int> t;

    Segment() {}
    Segment(int _n, vector<int> a)
    {
        for(n = 1; n <= _n; n <<= 1);
        t.resize(2*n);
        for(int i = 0; i < _n; ++i) t[i+n] = a[i];
        for(int i = n-1; i >= 0; i--) t[i] = t[2*i]+t[2*i+1];
    }

    void update(int p, int v)
    {
        for(t[p+=n] = v; p > 1; p >>= 1)
        {
            t[p>>1] = t[p] + t[p^1];
        }
    }

    int query(int l, int r)
    {
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if(l&1) res += t[l++];
            if(r&1) res += t[--r];
        }
        return res;
    }

};
