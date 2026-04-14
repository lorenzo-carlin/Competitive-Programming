#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    vector<int> val;
    int cnt = 1;
    for(int i = 1; i < n; ++i, cnt++)
    {
        if(v[i] != v[i-1])
        {
            val.push_back(cnt);
            cnt = 0;
        }
    }
    val.push_back(cnt);
    
    bool cond = (v[0] == 0) ? (true) : (false);

    int ans = 0;
    for(int i = 0; i < val.size(); ++i, cond = !cond)
    {
        if(cond && val[i] >= k)
        {
            val[i] -= k;
            ans++;
            ans += (val[i] / (k+1));
        }
    }

    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
