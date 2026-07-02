#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k; cin >> n >> k;
    int sum = 0;
    for(int i = 0, c; i < n; i++)
    {
        cin >> c;
        sum += c;
    }

    if(sum & 1)
    {
        cout << "YES\n";
    } else if(k*n & 1)
    {
        cout << "NO\n";
    } else
    {
        cout << "YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
