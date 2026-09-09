#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, d; cin >> n >> d;
    ll p = pow(10, n-1);
    ll num1 = d*2, num2 = d;
    while(num1 / p == 0) num1 *= 2;
    while(num2 / p == 0) num2 *= 3;
    if(num1/p < 10 && num2/p < 10) cout << num1 << " " << num2 << "\n";
    else cout << 0 << " " << 0 << "\n";
}