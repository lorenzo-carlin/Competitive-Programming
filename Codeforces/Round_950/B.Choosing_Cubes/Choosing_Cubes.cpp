#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, f, k; cin >> n >> f >> k;
    vector<int> v(n);
    for(int &i: v) cin >> i;
    int t = v[f-1];
    sort(rbegin(v), rend(v));

    if(v[k-1] > t) cout << "NO\n";
    else if(v.size() == k || (v[k-1] <= t && v[k] < t)) cout << "YES\n";
    else cout << "MAYBE\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}