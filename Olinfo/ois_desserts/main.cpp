#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, p; cin >> n >> p;
    vector<int> s(n), f(n);
    for(int &i: s) cin >> i;
    for(int &i: f) cin >> i;

    vector<int> v;
    for(int i = 0; i < n; i++)
        if(f[i] == p)
            v.push_back(s[i]);
    sort(begin(v), end(v));

    int q; cin >> q;
    while(q--)
    {
        int l, r, k; cin >> l >> r >> k;
        int cnt = upper_bound(begin(v), end(v), r) - lower_bound(begin(v), end(v), l);
        if(cnt >= k) cout << "YES\n";
        else cout << "NO\n";
    }
}
