#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(begin(v), end(v));

    cout << (v[0]^v[1]^v[2])-v[1] << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
