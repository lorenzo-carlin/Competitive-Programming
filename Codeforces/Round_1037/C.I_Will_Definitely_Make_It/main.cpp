#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k; cin >> n >> k; k--;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    int h = v[k];

    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));

    int idx = 0;
    while(v[idx] < h)
        idx++;

    bool possible = true;
    int cur_h = 1, last = -1;
    while(idx < v.size()-1)
    {
        // provo a fare il prossimo passo
        last = v[idx];
        idx++;
        cur_h += (v[idx] - last);
        if(cur_h-1 > last)
            possible = false;
    }

    if(possible) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
