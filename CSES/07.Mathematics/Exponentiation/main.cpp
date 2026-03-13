#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9+7;

ll fast_exp(int a, int b)
{
    if(b == 0) return 1;
    ll t = fast_exp(a, b/2)%mod;
    ll ris = (t * t)%mod;
    if(b % 2)
    {
        ris = (ris*a)%mod;
    }
    return ris%mod;
}

int main()
{
    int n; cin >> n;
    while(n--)
    {
        int a, b; cin >> a >> b;
        cout << fast_exp(a, b) << "\n";
    }
}