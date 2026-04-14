#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n; cin >> n;
    vector<ll> ans;
    for(int i = 1; i <= 18; ++i)
    {
        ll tmp = pow(10, i);
        if(n % (tmp+1) == 0)
        {
            ans.push_back(n/(tmp+1));
        }
    }

    cout << ans.size() << "\n";
    sort(begin(ans), end(ans));
    if(ans.size() == 0) return;
    for(auto el: ans) cout << el << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
