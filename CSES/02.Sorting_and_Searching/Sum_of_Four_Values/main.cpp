#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    map<ll,pair<int,int>> mp;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            ll sum = v[i] + v[j];
            ll rem = x - sum;
            if(mp.count(rem))
            {
                auto [k, l] = mp[rem];
                if(k == i || k == j || l == i || l == j) continue;
                cout << i+1 << " " << j+1 << " " << k+1 << " " << l+1 << "\n";
                return 0;
            }
        }
        for(int j = i+1; j < n; ++j)
        {
            mp[v[i]+v[j]] = {i, j};
        }
    }

    cout << "IMPOSSIBLE\n";
}
