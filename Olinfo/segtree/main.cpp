#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MIN = LONG_LONG_MIN;
const ll MAX = LONG_LONG_MAX;

struct Segment
{
    struct node
    {
        ll sum = 0;
        ll min = MAX;
        ll lazy = 0;
        ll set = MAX;

        node() { sum = 0, min = MAX, lazy = 0, set = MAX; }
        node(ll a, ll b) { sum = a, min = b, lazy = 0, set = MAX; }
    };
    
    ll n;
    vector<node> t;

    node unisci(node a, node b) { return node(a.sum + b.sum, min(a.min, b.min)); }

    Segment() {}

    Segment(ll _n, vector<ll> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(ll i = 0; i < _n; ++i) t[i+n] = node(a[i], a[i]);
        for(ll i = n-1; i > 0; --i) t[i] = unisci(t[2*i], t[2*i+1]);
    }

    void propaga(ll i, ll tl, ll tr)
    {
        if(t[i].lazy != 0)
        {
            t[i].sum += t[i].lazy * (tr - tl + 1);
            t[i].min += t[i].lazy;
            if(tl != tr)
            {
                if(t[2*i].set != MAX)
                {
                    t[2*i].set += t[i].lazy;
                    t[2*i].lazy = 0;
                } else
                {
                    t[2*i].lazy += t[i].lazy;
                }
                if(t[2*i+1].set != MAX)
                {
                    t[2*i+1].set += t[i].lazy;
                    t[2*i+1].lazy = 0;
                } else
                {
                    t[2*i+1].lazy += t[i].lazy;
                }
            }
            t[i].lazy = 0;
        } else if(t[i].set != MAX)
        {
            t[i].lazy = 0;
            t[i].sum = t[i].set * (tr - tl + 1);
            t[i].min = t[i].set;
            if(tl != tr)
            {
                t[2*i].set = t[i].set;
                t[2*i].lazy = 0;
                t[2*i+1].set = t[2*i+1].set;
                t[2*i+1].lazy = 0;
            }
            t[i].set = MAX;
        }
    }

    void add_update(int i, int tl, int tr, int l, int r, ll x)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r)
        {
            if(t[i].set != MAX) t[i].set += x;
            else t[i].lazy += x;
            propaga(i, tl, tr);
        } else
        {
            int tm = (tl + tr) / 2;
            add_update(2*i, tl, tm, l, r, x);
            add_update(2*i+1, tm+1, tr, l, r, x);
            t[i] = unisci(t[2*i], t[2*i+1]);
        }
    }

    void add_update(int l, int r, ll x) {add_update(1, 0, n-1, l, r, x);}

    ll sum_query(int i, int tl, int tr, int l, int r)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i].sum;
        int tm = (tl + tr) / 2;
        return sum_query(2*i, tl, tm, l, r) + sum_query(2*i+1, tm+1, tr, l, r);
    }

    ll sum_query(int l, int r) {return sum_query(1, 0, n-1, l, r);}

    ll min_query(int i, int tl, int tr, int l, int r)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return MAX;
        if(l <= tl && tr <= r) return t[i].min;
        int tm = (tl + tr) / 2;
        return min(min_query(2*i, tl, tm, l, r), min_query(2*i+1, tm+1, tr, l, r));
    }

    ll min_query(int l, int r) {return min_query(1, 0, n-1, l, r);}

    int lower_bound_query(int i, int tl, int tr, int l, int r, ll x)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return -1;
        if(t[i].min > x) return -1;
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        ll sx = lower_bound_query(2*i, tl, tm, l, r, x);
        if(sx != -1) return sx;
        return lower_bound_query(2*i+1, tm+1, tr, l, r, x);
    }

    ll lower_bound_query(int l, int r, ll x) {return lower_bound_query(1, 0, n-1, l, r, x);}

    void set_range_update(int i, int tl, int tr, int l, int r, ll x)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r)
        {
            t[i].lazy = 0;
            t[i].set = x;
            propaga(i, tl, tr);
        } else
        {
            int tm = (tl + tr) / 2;
            set_range_update(2*i, tl, tm, l, r, x);
            set_range_update(2*i+1, tm+1, tr, l, r, x);
            t[i] = unisci(t[2*i], t[2*i+1]);
        }
    }

    void set_range_update(int l, int r, ll x) {set_range_update(1, 0, n-1, l, r, x);}

    void stampa()
    {
        for(ll i = 1; i < t.size(); ++i)
        {
            cout << i << ": " << t[i].sum << "\n";
        }
    }
};

Segment st;

void init(vector<ll> a)
{
    st = Segment(a.size(), a);
}

ll get_sum(int l, int r)
{
    return st.sum_query(l, r-1);
}

void add(int l, int r, ll x)
{
    st.add_update(l, r-1, x);
}

void set_range(int l, int r, ll x)
{
    st.set_range_update(l, r-1, x);
}

ll get_min(int l, int r)
{
    return st.min_query(l, r-1);
}

ll lower_bound(int l, int r, ll x)
{
    return st.lower_bound_query(l, r-1, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(auto &el: a) cin >> el;
    init(a);
    int t, b, c;
    ll d;
    for(int i = 0; i < q; ++i)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> b >> c;
            cout << get_sum(b, c) << "\n";
        } else if(t == 2)
        {
            cin >> b >> c >> d;
            add(b, c, d);
            //st.stampa();
        } else if(t == 3)
        {
            cin >> b >> c >> d;
            set_range(b, c, d);
        } else if(t == 4)
        {
            cin >> b >> c;
            cout << get_min(b, c) << "\n";
        } else if(t == 5)
        {
            cin >> b >> c >> d;
            cout << lower_bound(b, c, d) << "\n";
        }
    }

}