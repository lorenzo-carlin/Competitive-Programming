#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LOG = 30;
constexpr int MAXN = 2e5 + 5;
vector<int> par(MAXN);
int up[MAXN][LOG];

int lift(int a, int k)
{
    for(int i = 0; i < LOG; ++i)
    {
        if(k & (1 << i)) a = up[a][i];
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 0; i < n; ++i)
    {
        cin >> par[i];
        --par[i];
    }

    for(int i = 0; i < n; ++i)
    {
        up[i][0] = par[i];
    }
    
    for(int j = 1; j < LOG; ++j)
    {
        for(int i = 0; i < n; ++i)
        {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    for(int i = 0, a, b; i < q; ++i)
    {
        cin >> a >> b; --a;
        cout << lift(a, b)+1 << "\n";
    }
}