#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for(auto &i: v) cin >> i;

        priority_queue<int> pq;
        int sol = 0;

        for(int i = 0; i < n; ++i, k--)
        {
            if(v[i] != 0) pq.push(v[i]);

            if(k == 1 && !pq.empty())
            {
                sol++;
                k += pq.top();
                pq.pop();
            }

            if(k == 0 && pq.empty())
            {
                sol = -1;
                break;
            }
        }

        if(k == 1 && !pq.empty())
        {
            sol++;
            k += pq.top();
            pq.pop();
        }
        
        if(k == 0 && pq.empty())
        {
            sol = -1;
            break;
        }

        cout << "Case #" << x << ": " << sol << "\n";
    }
}