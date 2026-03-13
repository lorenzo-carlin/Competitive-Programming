#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    ll sol = (ll)(n/2+1)*(n-(n/2)+1);
    cout << sol << "\n";
}