#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int l = 1; l <= t; ++l)
    {
        int n, m; cin >> n >> m;
        vector<vector<char>> tab(n);

        // input iniziale
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                char c; cin >> c;
                tab[i].push_back(c);
            }
        }

        priority_queue<int> x;
        priority_queue<int> revx;
        priority_queue<int> y;
        priority_queue<int> revy;

        // input modificato
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                char c; cin >> c;
                if(c != tab[i][j])
                {
                    x.push(i);
                    revx.push(-i);
                    y.push(j);
                    revy.push(-j);
                }
            }
        }

        ll ans;
        if(x.empty() && y.empty())
        {
            ans = 0;
        } else
        {
            int b = x.top() + revx.top() + 1;
            int h = y.top() + revy.top() + 1;
            ans = b*h;
        }
        cout << "Case #" << l << ": " << ans << "\n";
    }
}