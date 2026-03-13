#include <bits/stdc++.h>
#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("O3")
#pragma GCC Optimize("O2")
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int ans = 0;
    char c;
    while(n--)
    {
        cin >> c;
        ans ^= int(c);
    }

    cout << char(ans) << "\n";
}
