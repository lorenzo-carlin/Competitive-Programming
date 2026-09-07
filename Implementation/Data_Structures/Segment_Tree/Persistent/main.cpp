#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    Node *l, *r;
    int sum;

    Node(int v) : l(nullptr), r(nullptr), sum(v) {}
    Node(Node *l, Node *r) : l(l), r(r), sum(0)
    {
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }
};

struct PersistentSegTree
{
    int n;
    vector<Node*> root;

    PersistentSegTree() {}
    PersistentSegTree(vector<int> v)
    {
        int _n = v.size();
        for(n = 1; n < _n; n <<= 1);
        root.push_back(build(v, 0, n-1));
    }

    Node* build(vector<int> &v, int tl, int tr)
    {
        if(tl == tr) return new Node(v[tl]);
        int tm = (tl + tr) / 2;
        Node *l = build(v, tl, tm);
        Node *r = build(v, tm+1, tr);
        return new Node(l, r);
    }

    int query(Node *v, int tl, int tr, int l, int r)
    {
        if(tr < l || tl > r) return 0;
        if(l <= tl && tr <= r) return v->sum;
        int tm = (tl + tr) / 2;
        return query(v->l, tl, tm, l, r) + query(v->r, tm+1, tr, l, r);
    }

    int query(int age, int l, int r)
    {
        if(age >= root.size()) return -1;
        return query(root[age], 0, n-1, l, r);
    }

    Node* update(Node *v, int tl, int tr, int p, int x)
    {
        if(p < tl || tr < p) return v;
        if(tl == tr && tl == p) return new Node(x);
        int tm = (tl + tr) / 2;
        Node *l = update(v->l, tl, tm, p, x);
        Node *r = update(v->r, tm+1, tr, p, x);
        return new Node(l, r);
    }

    void update(int p, int x)
    {
        root.push_back(update(root.back(), 0, n-1, p, x));
    }
};

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    PersistentSegTree seg = PersistentSegTree(v);

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
            int age, l, r; cin >> age >> l >> r;
            cout << seg.query(age, l, r) << "\n";
        }
    }
}
