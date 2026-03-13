#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<long double> p(n);
        priority_queue<pair<long double,int>> q;
        for(int i = 0; i < n; ++i)
        {
            cin >> p[i];
            q.push({p[i],i});
        }

        long double ans = 0;
        for(int i = 0; i < k; ++i)
        {
            long double prob = q.top().first;
            int ind = q.top().second;
            q.pop();

            long double next = prob*(1.0-p[ind]);
            ans += prob;
            q.push({next,ind});
        }

        cout << fixed << setprecision(6) << floor(ans*1000000) / 1000000 << "\n";
    }
}