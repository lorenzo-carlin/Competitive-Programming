#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* IDEA:
 * mantengo uno sparse_segment per le X e un segment per le Y
 * per ogni blocco aggiungo la larghezza all'intervallo delle y
 * e la lunghezza all'intervallo delle x
 * se è tutto coperto alla fine avrò che
 * per ogni x il valore massimo e minimo è lunghezza e
 * per ogni y il valore massimo e minimo è larghezza
 */

constexpr ll INF = 1e15;

struct Node
{
    ll mn = 0;
    ll mx = 0;
    ll left, right;

    bool lazy = false;
    int lazyv = 0;

    Node *l = nullptr, *r = nullptr;

    Node() {}
    Node(int _l, int _r) : left(_l), right(_r) {}
};

struct SparseSegment
{
    int n;
    Node *root;

    SparseSegment() {}
    SparseSegment(int _n)
    {
        for(n = 1; n <= _n; n <<= 1);
        root = new Node(0, n-1);
    }

    void expand(Node *v)
    {
        if(!v->l && v->left != v->right)
        {
            int m = (v->left + v->right) / 2;
            v->l = new Node(v->left, m);
            v->r = new Node(m+1, v->right);
        }
    }

    void propaga(Node *v)
    {
        if(v->lazy)
        {
            v->mn += v->lazyv;
            v->mx += v->lazyv;
            if(v->left != v->right)
            {
                (v->l)->lazy = (v->r)->lazy = true;
                (v->l)->lazyv += v->lazyv;
                (v->r)->lazyv += v->lazyv;
            }
            v->lazy = false;
            v->lazyv = 0;
        }
    }

    void update(Node *v, int l, int r, ll x)
    {
        if(v->right < l || r < v->left) return;
        expand(v);
        propaga(v);
        if(l <= v->left && v->right <= r)
        {
            v->lazy = true;
            v->lazyv += x;
        } else
        {
            int m = (v->left + v->right) / 2;
            update(v->l, l, r, x);
            update(v->r, l, r, x);
            v->mx = max((v->l)->mx, (v->r)->mx);
            v->mn = min((v->l)->mn, (v->r)->mn);
        }
    }

    void update(int l, int r, ll x)
    {
        update(root, l, r, x);
    }

    pair<ll,ll> query(Node *v, int l, int r) // {min, max}
    {
        if(v->right < l || r < v->left) return {INF, -INF};
        expand(v);
        propaga(v);
        if(l <= v->left && v->right <= r) return {v->mn, v->mx};
        auto a = query(v->l, l, r), b = query(v->r, l, r);
        return {min(a.first, b.first), max(a.second, b.second)};
    }

    pair<ll,ll> query(int l, int r)
    {
        return query(root, l, r);
    }
};

int main()
{
    SparseSegment X = SparseSegment(1e8);
    SparseSegment Y = SparseSegment(1e8);

    ll mx_x = 0, mx_y = 0, mn_x = 1e9, mn_y = 1e9;

    int n; cin >> n;
    while(n--)
    {
        ll x, y, w, h; cin >> x >> y >> w >> h;
        mn_x = min(mn_x, x);
        mx_x = max(mx_x, x+w-1);
        mn_y = min(mn_y, y);
        mx_y = max(mx_y, y+h-1);

        X.update(x, x+w-1, h);
        Y.update(y, y+h-1, w);

        auto p1 = X.query(0, 5);
        auto p2 = Y.query(0, 5);
        cout << p1.first << " " << p1.second << "\n";
        cout << p2.first << " " << p2.second << "\n";
    }

    auto a = X.query(mn_x, mx_x);
    auto b = Y.query(mn_y, mx_y);

    cout << a.first << " " << a.second << "\n";
    cout << b.first << " " << b.second << "\n";

    ll H = mx_y-mn_y+1;
    ll W = mx_x-mn_x+1;

    if(a.first != H || a.second != H || b.first != W || b.second != W) cout << "no\n";
    else cout << "yes\n";
}
