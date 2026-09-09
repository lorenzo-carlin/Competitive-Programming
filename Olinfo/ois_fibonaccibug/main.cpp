#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXFIBO = 27;
const int MAXK = 1e5+5;
int fibo[MAXFIBO];
int N, W;

void precalculate()
{
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i = 2; i < MAXFIBO; ++i) fibo[i] = fibo[i-1] + fibo[i-2];
}

ll unbounded_knapsack(int ind, int curr, vector<int> &p, vector<vector<ll>> &memo, vector<vector<bool>> &vis)
{
    if(curr < 0) return -1e9;
    if(ind == MAXFIBO || curr == 0) return 0;

    if(vis[ind][curr]) return memo[ind][curr];
    vis[ind][curr] = true;

    ll mx = unbounded_knapsack(ind+1, curr, p, memo, vis);
    if(p[ind] != -1) mx = max(mx, unbounded_knapsack(ind, curr-fibo[ind], p, memo, vis)+p[ind]);

    return memo[ind][curr] = mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precalculate();

    int t; cin >> t;
    while(t--)
    {
        cin >> N >> W;
        vector<int> p(MAXFIBO, -1);
        for(int i = 0; i < N; ++i)
        {
            int a, b; cin >> a >> b;
            if(a < MAXFIBO) p[a] = max(p[a], b);
        }

        vector<vector<ll>> memo(MAXFIBO+2, vector<ll>(MAXK, 0));
        vector<vector<bool>> vis(MAXFIBO+2, vector<bool>(MAXK, false));

        cout << unbounded_knapsack(0, W, p, memo, vis) << "\n";
    }
}