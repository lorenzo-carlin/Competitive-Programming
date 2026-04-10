#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k, q; cin >> n >> k >> q;
    vector<int> v(n, -1);
    vector<bool> q1(n, false), q2(n, false);

    vector<array<int,3>> queries(q);
    for(int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        queries[i][1]--;
        queries[i][2]--;
        for(int j = queries[i][1]; j <= queries[i][2]; j++)
        {
            if(queries[i][0] == 1) q1[j] = true;
            else q2[j] = true;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(q1[i] && q2[i]) v[i] = k+1;
        else if(q1[i]) v[i] = k;
        else if(!q1[i] && !q2[i]) v[i] = 0;
    }

    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == -1)
        {
            v[i] = idx%k;
            idx++;
        }
    }

    for(int el: v) cout << el << " ";
    cout << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
