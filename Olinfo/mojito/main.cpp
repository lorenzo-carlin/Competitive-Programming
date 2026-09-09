#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

struct co
{
    int x, y;
    co(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    co() {}
};

int dist(co a, co b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int r, c; cin >> r >> c;

    co mojito = co();
    cin >> mojito.x >> mojito.y;

    int n; cin >> n;
    vector<pair<co,co>> pl(n);
    for(int i = 0; i < n; ++i) cin >> pl[i].f.x >> pl[i].f.y >> pl[i].s.x >> pl[i].s.y;

    vector<bool> vis(n, false);
    // trovo il giocatore da cui parte il gioco (quello più vicino a mojito)
    int mn = 1e9, st = -1;
    co mnn_st, mnn_fn;
    for(int i = 0; i < n; ++i)
    {
        int d = dist(mojito, pl[i].f);
        if(((d < mn) || (d == mn && pl[i].f.x < mnn_st.x) || (d == mn && pl[i].f.x == mnn_st.x && pl[i].f.y < mnn_st.y)))
        {
            mn = d;
            st = i;
            mnn_st = pl[i].f;
            mnn_fn = pl[i].s;
        }
    }

    int cont = 0;
    int tmp = st;
    co curr_st = mnn_st, curr_fn = mnn_fn;
    // mn = 1e9, st = -1;
    while(!vis[tmp])
    {
        // cout << tmp << " ";
        vis[tmp] = true;

        mn = 1e9, st = -1;
        // trovo il giocatore più vicino a tmp
        for(int i = 0; i < n; ++i)
        {
            // if(i == tmp) continue;

            int d = dist(curr_fn, pl[i].f);
            if(((d < mn) || (d == mn && pl[i].f.x < mnn_st.x) || (d == mn && pl[i].f.x == mnn_st.x && pl[i].f.y < mnn_st.y)))
            {
                mn = d;
                st = i;
                mnn_st = pl[i].f;
                mnn_fn = pl[i].s;
            }
        }

        tmp = st;
        curr_st = mnn_st;
        curr_fn = mnn_fn;

        cont++;

        // cout << tmp << "\n";
    }

    cout << cont << "\n";
}
