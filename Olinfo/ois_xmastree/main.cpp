#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main()
{
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0, a, b; i < n-1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> A(n);
    for(int &i: A) cin >> i;

    vector<array<ll,2>> dp(n);
    auto solve = [&] (auto solve, int v, int p) -> void
    {
        dp[v][0] = dp[v][1] = -INF;
        ll sum0 = 0, sum1 = 0, cur0 = 0, cur1 = 0;

        vector<int> children;
        for(int u: adj[v])
        {
            if(u == p) continue;

            solve(solve, u, v);
            children.push_back(u);
            sum0 += dp[u][0];
            sum1 += dp[u][1];
        }
        int sz = children.size();

        if(sz == 0)
        {
            dp[v][0] = A[v];
            dp[v][1] = 0;
            return;
        }

        sort(begin(children), end(children), [&](int a, int b) {
                return dp[a][0] > dp[b][0];
        });

        // calcolo dp[i][0] a partire da f = 0
        if(sz & 1)
        {
            cur0 = 0, cur1 = 0;
            for(int j = 0; j < sz; j++)
            {
                if(j & 1)
                    dp[v][0] = max(dp[v][0], cur0+(sum1-cur1));
                cur0 += dp[children[j]][0];
                cur1 += dp[children[j]][1];
            }
            if(sz & 1)
                dp[v][0] = max(dp[v][0], cur0+(sum1-cur1));
        } else
        {
            cur0 = 0, cur1 = 0;
            for(int j = 0; j < sz; j++)
            {
                if(!(j & 1))
                    dp[v][0] = max(dp[v][0], cur0+(sum1-cur1));
                cur0 += dp[children[j]][0];
                cur1 += dp[children[j]][1];
            }
            if(!(sz & 1))
                dp[v][0] = max(dp[v][0], cur0+(sum1-cur1));
        }

        // calcolo dp[i][1] partire da f = 0
        if(sz & 1)
        {
            cur0 = 0, cur1 = 0;
            for(int j = 0; j < sz; j++)
            {
                if(!(j & 1))
                    dp[v][1] = max(dp[v][1], cur0+(sum1-cur1));
                cur0 += dp[children[j]][0];
                cur1 += dp[children[j]][1];
            }
            if(!(sz & 1))
                dp[v][1] = max(dp[v][1], cur0+(sum1-cur1));
        } else
        {
            cur0 = 0, cur1 = 0;
            for(int j = 0; j < sz; j++)
            {
                if(j & 1)
                    dp[v][1] = max(dp[v][1], cur0+(sum1-cur1));
                cur0 += dp[children[j]][0];
                cur1 += dp[children[j]][1];
            }
            if(sz & 1)
                dp[v][1] = max(dp[v][1], cur0+(sum1-cur1));
        }

        sort(begin(children), end(children), [&](int a, int b) {
                return dp[a][1] > dp[b][1];
        });

        // calcolo dp[i][1] a partire da f = 1
        cur0 = 0, cur1 = 0;
        for(int j = 0; j < sz; j++)
        {
            if(j & 1)
                dp[v][1] = max(dp[v][1], cur1+(sum0-cur0));
            cur0 += dp[children[j]][0];
            cur1 += dp[children[j]][1];
        }
        if(sz & 1)
            dp[v][1] = max(dp[v][1], cur1+(sum0-cur0));

        // calcolo dp[i][0] a partire da f = 1
        cur0 = 0, cur1 = 0;
        for(int j = 0; j < sz; j++)
        {
            if(!(j & 1))
                dp[v][0] = max(dp[v][0], cur1+(sum0-cur0));
            cur0 += dp[children[j]][0];
            cur1 += dp[children[j]][1];
        }
        if(!(sz & 1))
            dp[v][0] = max(dp[v][0], cur1+(sum0-cur0));

        dp[v][0] += A[v];
    };

    solve(solve, 0, -1);

    cout << max(dp[0][0], dp[0][1]) << "\n";
}
