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
        ll max = MIN;
        ll add = 0;
        bool set = false;
        ll set_v = 0;
    };
    
    ll n;
    vector<node> t;

    node unisci(node a, node b)
    {
        node res;
        res.min = min(a.min, b.min);
        res.max = max(a.max, b.max);
        res.sum = a.sum + b.sum;
        return res;
    }

    Segment() {}

    Segment(ll _n, vector<ll> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(ll i = 0; i < _n; ++i) t[i+n].min = t[i+n].max = t[i+n].sum = a[i];
        for(ll i = n-1; i >= 0; --i) t[i] = unisci(t[2*i], t[2*i+1]);
    }

    void propaga(ll i, ll tl, ll tr)
    {
        if(t[i].set)
        {
            t[i].sum = t[i].set_v * (tr - tl + 1);
            t[i].max = t[i].set_v;
            t[i].min = t[i].set_v;
            if(tl != tr)
            {
                t[2*i].set = true;
                t[2*i].set_v = t[i].set_v;
                t[2*i+1].set= true;
                t[2*i+1].set_v = t[i].set_v;
            }
            t[i].set = false;
        }
        if(t[i].add != 0)
        {
            t[i].sum += t[i].add * (tr - tl + 1);
            t[i].min += t[i].add;
            t[i].max += t[i].add;
            if(tl != tr)
            {
                t[2*i].add = t[i].add;
                t[2*i+1].add = t[i].add;
            } else
            {
                t[i].min = t[i].max = t[i].sum;
            }
            t[i].add = 0;
        }
    }

    void add_update(int i, int tl, int tr, int l, int r, ll x)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r)
        {
            t[i].add += x;
            propaga(i, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        add_update(2*i, tl, tm, l, r, x);
        add_update(2*i+1, tm+1, tr, l, r, x);
        t[i] = unisci(t[2*i], t[2*i+1]);
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

    ll lower_bound_query(int i, int tl, int tr, int l, int r, ll x)
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
            t[i].add = 0;
            t[i].set = true;
            t[i].set_v = x;
            propaga(i, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        set_range_update(2*i, tl, tm, l, r, x);
        set_range_update(2*i+1, tm+1, tr, l, r, x);
        t[i] = unisci(t[2*i], t[2*i+1]);
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
            st.stampa();
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