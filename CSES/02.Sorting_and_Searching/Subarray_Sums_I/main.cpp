#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;

    vector<ll> v;
    v.push_back(0);

    vector<ll> prefix_sums;
    prefix_sums.push_back(0);

    map<ll,ll> count;
    count[0] = 1;
    ll num;

    for(int i = 0; i < n; ++i)
    {
        cin >> num; v.push_back(num);
        prefix_sums.push_back(prefix_sums.back() + v.back());
        count[prefix_sums.back()]++;
    }

    ll ans = 0;
    if(x == 0) count[0]--;
    for(int i = 0; i <= n; ++i)
    {
        ll val = prefix_sums[i];
        ans += count[x + val];
        count[val]--;
    }

    cout << ans << "\n";
    return 0;
}