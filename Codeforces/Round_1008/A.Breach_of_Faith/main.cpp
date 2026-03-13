#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<ll> b(2*n);
    for(auto &i: b) cin >> i;
    sort(rbegin(b), rend(b));

    vector<ll> a(2*n+1);
    for(int i = 0; i < n+1; i++)
        a[2*i] = b[i];
    for(int i = 0; i < n-1; i++)
        a[2*i+1] = b[n+1+i];

    ll t = a[0] + a[2*n];
    for(int i = 1; i < n; i++)
        t += (a[2*i] - a[2*i-1]);

    a[2*n-1] = t;

    for(auto el: a) cout << el << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
