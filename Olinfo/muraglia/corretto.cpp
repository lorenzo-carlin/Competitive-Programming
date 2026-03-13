#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct Segment
{
    int n;
    vector<ll> t;
    
   
    Segment(int _n, vector<int> v)
    {
        for(n = 1; n <= _n; n <<= 1);
        // t.resize(2*_n, 0);
		t.resize(2*n, 0);	// errore mio nell'implementazione iniziale
        for(int i = 0; i < _n; ++i)
            t[i+n] = v[i];
        // for(int i = _n-1; i > 0; --i)
		for(int i = n-1; i > 0; --i)	// errore mio nell'imlementazione iniziale
            t[i] = max(t[2*i], t[2*i+1]);
    }
   
    Segment() {}
   
    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr)
        {
            t[i] = v;
        } else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = max(t[2*i], t[2*i+1]);
        }

    }
   
    int queryr(int i, int tl, int tr, int l, int r, int k)
    {
        if(r < tl || tr < l) return -1;
        if(t[i]<=k) return -1; 
        if(tl == tr && t[i] <= k) return -1;
        if(tl == tr && t[i] > k) return tl;
        int tm = (tl + tr) / 2;
        
        int a = queryr(2*i, tl, tm, l, r, k);
        if(a==-1) return queryr(2*i+1, tm+1, tr, l, r, k);
        else return a;
  
    }

    int queryl(int i, int tl, int tr, int l, int r, int k)
    {
        if(r < tl || tr < l) return -1;
        if(t[i]<=k) return -1; 
        if(tl == tr && t[i] <= k) return -1;
        if(tl == tr && t[i] > k) return tl;
        int tm = (tl + tr) / 2;
        
        int a = queryl(2*i+1, tm+1, tr, l, r, k);
        if(a==-1) return queryl(2*i, tl, tm, l, r, k);
        else return a;
    }
   
};

// Bisoga distinguere due 'n':
// n = N = dimensione dell'array dato in input
// seg.n, ossia l'n della struct seg, che è invece la dimensione del segtree

Segment seg;
vector<int> h;
int n;
void inizializza(int N, vector<int> H)
{
    seg = Segment(N, H);
    h=H;
    n = N;
}


void cambia(int x, int h)
{
   	// seg.update(1, 0, n-1, x, h);
	seg.update(1, 0, seg.n-1, x, h);
}

pair<int, int> chiedi(int x)
{
    //int left = seg.queryr(1, 0, n-1, 0, x-1, h[x]);
	int left = seg.queryl(1, 0, seg.n-1, 0, x-1, seg.t[seg.n+x]);
	// !! abbiamo invertito queryr e queryl, XD
	// tr dev'essere uguale a seg.n, dimensione del segtree
	// dobbiamo sostituire h[x] perché quando facciamo gli uodate lo modifichiamo nel
	// segtree, non in h, quindi h[x] rimane semmpre lo stesso
	// seg.t[seg.n+x] è trova il valore di h[x] nel segment, che però è aggiornato
    // int right = seg.queryl(1, 0, n-1, x+1, n-1, h[x]);
	int right = seg.queryr(1, 0, seg.n-1, x+1, n-1, seg.t[seg.n+x]);
	// stesse cosa di quelle dette sopra
    if(left==-1)
        left=0;
    if(right==-1)
        right=n-1;
    return make_pair(left, right);
}
