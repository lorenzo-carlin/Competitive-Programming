#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    int px, py, qx, qy; cin >> px >> py >> qx >> qy;
    vector<double> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    a.push_back(sqrt((px-qx)*(px-qx)+(py-qy)*(py-qy)));
    sort(begin(a), end(a));
    double sum = a[n];
    for(int i = 0; i < n; i++)
    {
        sum -= a[i];
    }

    if(sum <= 0) cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
