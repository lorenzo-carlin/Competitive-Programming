#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k; cin >> n >> k;

    vector<int> v(n);
    for(int &i: v) cin >> i;
    sort(begin(v), end(v));

    multiset<int> ms;
    for(int i: v) ms.insert(i);

    for(int i = n; i > 0; i--)
    {
        int maggiori = (v.end() - lower_bound(begin(v), end(v), 4*i));
        int uguali = ms.count(3*i) + ms.count(2*i) + ms.count(i);
        if(k >= (n-maggiori-uguali))
        {
            cout << i << "\n";
            return;
        }
    }
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
