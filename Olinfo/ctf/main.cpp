#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fast_pow(ll base, ll exp)
{
    if(exp == 0) return 1;
    ll sol = fast_pow(base, exp/2);
    sol = sol*sol;
    if(exp % 2 == 1) sol = sol * base;
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q; cin >> q;
    while(q--)
    {
        ll num; cin >> num;
        int a = log2(num);
        ll lwb = fast_pow(2, a);
        ll sol = (num-lwb+1)*2-1;
        cout << sol << "\n";
    }
}