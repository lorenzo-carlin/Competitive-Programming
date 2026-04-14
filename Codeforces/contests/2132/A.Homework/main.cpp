#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    string a; cin >> a;
    int m; cin >> m;
    string b, c; cin >> b >> c;
    for(int i = 0; i < m; ++i)
    {
        if(c[i] == 'D') a.push_back(b[i]);
        else a.insert(a.begin(),b[i]);
    }

    cout << a << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
