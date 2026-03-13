#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    int sum = 0;
    ll left, right;
    Node *l = nullptr, *r = nullptr;

    Node() {}
    Node(ll _l, ll _r) : left(_l), right(_r) {}
};

struct SparseSegTree
{
    ll n;
    Node *root;

    SparseSegTree() {}
    SparseSegTree(int _n)
    {
        for(n = 1; n < _n; n <<= 1);
        root = new Node(0, n-1);
    }

    void extend(Node *v)
    {
        if(!v->l && v->left != v->right)
        {
            int m = (v->left + v->right) / 2;
            v->l = new Node(v->left, m);
            v->r = new Node(m+1, v->right);
        }
    }

    void update(Node *v, int p, int x)
    {
        extend(v);
        if(p < v->left || p > v->right) return;
        if(v->left == v->right && v->left == p) v->sum = x;
        else
        {
            update(v->l, p, x);
            update(v->r, p, x);
            v->sum = (v->l)->sum + (v->r)->sum;
        }
    }

    void update(int p, int x)
    {
        update(root, p, x);
    }

    int query(Node *v, int l, int r)
    {
        if(v->right < l || r < v->left) return 0;
        if(l <= v->left && v->right <= r) return v->sum;
        extend(v);
        return query(v->l, l, r) + query(v->r, l, r);
    }

    int query(int l, int r)
    {
        return query(root, l, r);
    }
};

int main()
{
    int n; cin >> n;

    SparseSegTree seg = SparseSegTree(n);

    int q; cin >> q;
    while(q--)
    {
        int type; cin >> type;
        if(type == 0) // update
        {
            int p, x; cin >> p >> x;
            seg.update(p, x);
        } else // query
        {
            int l, r; cin >> l >> r;
            cout << seg.query(l, r) << "\n"; 
        }
    }
}
