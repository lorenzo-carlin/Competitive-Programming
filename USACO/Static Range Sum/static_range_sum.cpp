#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q; cin >> n >> q;
    vector<ll> v;
    v.push_back(0);

    vector<ll> prefix_sums;
    prefix_sums.push_back(0);

    ll num;
    for(int i = 0; i < n; ++i)
    {
        cin >> num;
        v.push_back(num);
        prefix_sums.push_back(prefix_sums.back() + v[i+1]);
    }

    for(int i = 0; i < q; ++i)
    {
        int a, b; cin >> a >> b;
        cout << prefix_sums[b] - prefix_sums[a] << "\n";
    }
}