#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
    vector<int> par;
    vector<array<int,3>> cnt;   // [0] : sasso, [1] : carta, [2] : forbice
    int n;

    DSU() {}

    DSU(int _n, string s) : n(_n)
    {
        par.resize(n);
        iota(begin(par), end(par), 0);
        cnt.resize(n);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'S') cnt[i][0]++;
            if(s[i] == 'C') cnt[i][1]++;
            if(s[i] == 'F') cnt[i][2]++;
        }
    }

    int find(int a)
    {
        return (par[a] == a) ? (a) : (par[a] = find(par[a]));
    }

    void merge(int a, int b)
    {
        int A = find(a);
        int B = find(b);
        if(A == b) return;

        cnt[B][0] += cnt[A][0];
        cnt[B][1] += cnt[A][1];
        cnt[B][2] += cnt[A][2];
        par[A] = B;
    }

    int sfida(int a, int b)
    {
        int A = find(a);
        int B = find(b);

        ll ptA = 0, ptB = 0;
        ptA += cnt[A][0]*cnt[B][2];
        ptA += cnt[A][1]*cnt[B][0];
        ptA += cnt[A][2]*cnt[B][1];
        ptB += cnt[B][0]*cnt[A][2];
        ptB += cnt[B][1]*cnt[A][0];
        ptB += cnt[B][2]*cnt[A][1];

        if(ptA > ptB) return a;
        else if(ptA < ptB) return b;
        else return -1;
    }
};

DSU dsu;

void organizza(int N, string T) {
    dsu = DSU(N, T);
}

int sfida(int a, int b) {
    return dsu.sfida(a, b);
}

void allea(int a, int b) {
    dsu.merge(a, b);
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, Q; cin >> N >> Q;

    string S; cin >> S;

    organizza(N, S);

    while(Q--) {
        int t, a, b; cin >> t >> a >> b;

        if(t == 2)
            allea(a, b);
        else if(t == 1)
            cout << sfida(a, b) << "\n";
    }
}

#endif
