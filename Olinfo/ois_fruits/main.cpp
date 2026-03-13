#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll A = 0, B = 0, C = 0;

    int n; cin >> n;
    vector<array<ll,3>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        A += v[i][0];
        B += v[i][1];
        C += v[i][2];
    }

    auto comp = [&] (array<ll,3> a, array<ll,3> b) -> bool
    {
        return (a[0]+a[1]+a[2]) > (b[0]+b[1]+b[2]);
    };

    sort(begin(v), end(v), comp);

    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        

    for(auto el: v)
    {
        cout << el[0] << " " << el[1] << " " << el[2] << "\n";
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
