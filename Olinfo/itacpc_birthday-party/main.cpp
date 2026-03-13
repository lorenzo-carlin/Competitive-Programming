#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> v(m);
    for(int i = 0, a; i < n; i++)
    {
        cin >> a;
        v[a%m].push_back(a);
    }

    for(int i = 0; i < m; i++)
        sort(rbegin(v[i]), rend(v[i]));

    vector<vector<ll>> ps(m);
    for(int i = 0; i < m; i++)
    {
        ps[i].assign(v[i].size()+1, 0);
        for(int j = 0; j < v[i].size(); j++)
        {
            ps[i][j+1] = ps[i][j] + v[i][j];
        }
    }

    vector<vector<ll>> S(m, vector<ll> (m, -INF));
    for(int i = 0; i < m; i++)
    {
        S[i][0] = 0;
        for(int j = 1; j < ps[i].size(); j++)
        {
            S[i][j%m] = max(S[i][j%m], ps[i][j]);
        }
    }

    vector<vector<ll>> dp(m, vector<ll> (m, -INF)), old(m, vector<ll> (m, -INF));
    old[0][0] = 0;
    for(int r = 0; r < m; r++)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(old[i][j] == -INF) continue;
                for(int q = 0; q < m; q++)
                {
                    if(S[r][q] == -INF) continue;
                    dp[(i+q)%m][(j+q*r)%m] = max(dp[(i+q)%m][(j+q*r)%m], old[i][j]+S[r][q]);
                }
            }
        }
        swap(dp, old);
    }

    cout << old[0][0] << "\n";
}
