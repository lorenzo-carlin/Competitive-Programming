#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    ll sol = 1, tmp = 1;

    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        tmp *= a;
        sol += tmp;
    }

    cout << sol << "\n";
}