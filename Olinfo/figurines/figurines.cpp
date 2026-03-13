#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Persistent_Segment
{
    struct Vertex
    {
        Vertex *l, *r;
        int sum;

        Vertex(int v) : l(nullptr), r(nullptr), sum(v) {}
        Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0)
        {
            if(l) sum += l->sum;
            if(r) sum += r->sum;
        }
    };

    int n;
    vector<Vertex*> t;

    Persistent_Segment() {}

    Persistent_Segment(int _n)
    {
        for(n = 1; n < _n; n <<= 1);
        Vertex *v = build(0, n-1);
        t.push_back(v);
    }

    Vertex* build(int tl, int tr)
    {
        if(tl == tr) return new Vertex(0);
        else
        {
            int tm = (tl + tr) / 2;
            return new Vertex(build(tl, tm), build(tm+1, tr));
        }
    }

    int query(Vertex *v, int tl, int tr, int l, int r)
    {
        //cerr << tl << " " << tr << " " << l << " " << r << "\n";
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return v->sum;
        int tm = (tl + tr) / 2;
        return query(v->l, tl, tm, l, r) + query(v->r, tm+1, tr, l, r);        
    }

    Vertex* update(Vertex* v, int tl, int tr, int p, int value)
    {
        if(tl == tr) return new Vertex(value);
        int tm = (tl + tr) / 2;
        if(p <= tm) return new Vertex(update(v->l, tl, tm, p, value), v->r);
        else return new Vertex(v->l, update(v->r, tm+1, tr, p, value));
    }

    void stampa(Vertex* v, int tl, int tr)
    {
        cout << v->sum << " ";
        if(tl == tr) return;
        int tm = (tl + tr) / 2;
        stampa(v->l, tl, tm);
        stampa(v->r, tm+1, tr);
    }
};

int sz, cont = 1;

Persistent_Segment st;

void init(int n)
{
    st = Persistent_Segment(n);
    sz = st.n;
}

void log(vector<int> &added, vector<int> &removed)
{
    st.t.push_back(st.t.back());
    for(auto el: added) st.t[cont] = st.update(st.t[cont], 0, sz-1, el, 1);
    for(auto el: removed) st.t[cont] = st.update(st.t[cont], 0, sz-1, el, 0);
    cont++;
}

int answer(int d, int x)
{
    if(d == 0) return 0;
    //st.stampa(st.t[d], 0, sz-1);
    //cout << "\n";
    //return 0;
    return st.query(st.t[d], 0, sz-1, x, sz-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	init(n);
	
	vector<int> added, removed;
	for (int i = 1; i <= n; i++) {
		added.clear();
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int k;
			cin >> k;
			added.push_back(k);
		}
		removed.clear();
		int r;
		cin >> r;
		for (int j = 0; j < r; j++) {
			int k;
			cin >> k;
			removed.push_back(k);
		}
		log(added, removed);
	}
	
	for (int i = 0; i < q; i++) {
		int d, x;
		cin >> d >> x;
		cout << answer(d, x) << "\n";
	}
	
	return 0;
}


// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, q; cin >> n >> q;
//     Segment st = Segment(n);

//     vector<pair<vector<int>,vector<int>>> v(n);
//     int a, b, c;
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> a;
//         while(a--)
//         {
//             cin >> c;
//             v[i].first.push_back(c);
//         }
//         cin >> b;
//         while(b--)
//         {
//             cin >> c;
//             v[i].second.push_back(c);
//         }
//     }

//     vector<pair<int,int>> r(q);
//     for(int i = 0; i < q; ++i)
//     {
//         cin >> r[i].first >> r[i].second;
//         r[i].first--;
//     }

//     int ind = 0;
//     for(int i = 0; i < n; ++i)
//     {
//         for(auto el: v[i].first) st.update(el, 1);
//         for(auto el: v[i].second) st.update(el, 0);

//         while(ind < q && r[ind].first <= i)
//         {
//             cout << st.query(r[ind].second, n-1) << "\n";
//             ind++;
//         }
//     }
// }