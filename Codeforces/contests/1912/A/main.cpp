#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x, k; cin >> x >> k;
    vector<vector<int>> l(k);
    for(int i = 0; i < k; i++)
    {
        int sz; cin >> sz;
        l[i].resize(sz);
        for(int &j: l[i]) cin >> j;
    }

    vector<vector<pair<ll,ll>>> block(k);
    for(int i = 0; i < k; i++)
    {
        ll sum = 0;
        ll mn_sum = 1e18;
        for(int j = 0; j < l[i].size(); j++)
        {
            sum += l[i][j];
            mn_sum = min(mn_sum, sum);
            if(sum > 0)
            {
                block[i].push_back({sum, mn_sum});
                sum = 0;
                mn_sum = 0;
            }
        }
    }

    vector<int> idx(k, 0);

    priority_queue<array<ll,3>> pq;
    for(int i = 0; i < k; i++)
    {
        if(block[i].empty()) continue;
        pq.push({block[i][0].second, block[i][0].first, i});
        idx[i]++;
    }

    while(!pq.empty())
    {
        ll mn = pq.top()[0];
        ll ss = pq.top()[1];
        ll ii = pq.top()[2];
        pq.pop();

        if(x + mn < 0)
        {
            cout << x << "\n";
            return 0;
        }
        x += ss;

        if(idx[ii] < block[ii].size())
        {
            pq.push({block[ii][idx[ii]].second, block[ii][idx[ii]].first, ii});
            idx[ii]++;
        }
    }

    cout << x << "\n";
}
