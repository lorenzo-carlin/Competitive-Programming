#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll lg = log2(n);
        ll st = pow(2, lg), fn = st*2-1;
        ll sol = 1, ind = 1;
        while(st != fn)
        {
            ll med = (st + fn) / 2;
            if(n <= med)
            {
                fn = med;
                ind = ind*2;
                sol += ind;
            } else
            {
                st = med+1;
                ind = ind*2+1;
                sol += ind;
            }
        }
        cout << sol << "\n";
    }
}