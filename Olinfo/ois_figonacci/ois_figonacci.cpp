#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, mod; cin >> n >> mod;

    int l1 = 0, l2 = -1;
    for(int i = 2; i <= n; ++i)
    {
        int tmp = l1;
        while(tmp - l2 < 0)
        {
            tmp += mod;
        }
        int t = (l1 + ((tmp - l2) % mod) * ((i-1) % mod)) % mod;
        l2 = l1;
        l1 = t;
    }

    cout << l1 << "\n";
}