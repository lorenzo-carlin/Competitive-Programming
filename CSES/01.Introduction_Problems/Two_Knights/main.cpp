#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(int n)
{
    if(n == 1) return 0;
    if(n == 2) return 6;
    if(n == 3) return 28;
    if(n == 4) return 96;
    ll dim = n*n;
    ll tot = 48, c = dim*(dim-1);
    tot += (((n-4)*4+(n-4)*6)*4)+((n-4)*(n-4)*8);
    ll res = (c-tot)/2;
    return res;
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cout << solve(i) << "\n";
    }
}