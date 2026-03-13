#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    int n;
    vector<ll> t;

	Segment() {}    
   
    Segment(int _n, vector<int> v)
    {
        for(n = 1; n <= _n; n <<= 1);
        t.resize(2*n, -1e9);
        for(int i = 0; i < _n; ++i)
            t[i+n] = v[i];
        for(int i = n-1; i > 0; --i)
            t[i] = max(t[2*i], t[2*i+1]);
    }
   
    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr && tl == p)
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
        if(t[i] <= k) return -1; 
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        
        int a = queryr(2*i, tl, tm, l, r, k);
		if(a != -1) return a;
		else return queryr(2*i+1, tm+1, tr, l, r, k);  
    }

    int queryl(int i, int tl, int tr, int l, int r, int k)
    {
        if(r < tl || tr < l) return -1;
        if(t[i]<=k) return -1; 
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        
        int a = queryl(2*i+1, tm+1, tr, l, r, k);
		if(a != -1) return a;
		else return queryl(2*i, tl, tm, l, r, k);
    }

	void print()
	{
		for(int i = 0; i < 2*n; ++i)
		{
			cout << i << ": " << t[i] << "\n";
		}
	}
   
};

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
    seg.update(1, 0, seg.n-1, x, h);
}

pair<int, int> chiedi(int x)
{
    int left = seg.queryl(1, 0, seg.n-1, 0, x-1, seg.t[seg.n+x]);
    int right = seg.queryr(1, 0, seg.n-1, x+1, n-1, seg.t[seg.n+x]);
    if(left==-1)
        left=0;
    if(right==-1)
        right=n-1;
	pair<int,int> ans = make_pair(left, right);
	return ans;
}

