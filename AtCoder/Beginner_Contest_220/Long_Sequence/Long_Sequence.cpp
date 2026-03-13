#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> v(n);
    for(auto &i:v) cin >> i;
    ll x; cin >> x;
    ll sum = accumulate(v.begin(), v.end(), 0);
    ll div = x / sum;
    ll cnt = div * n;
    sum = sum * div;
    for(int i = 0; i < n; ++i)
    {
        sum += v[i];
        cnt++;
        if(sum > x)
        {
            cout << cnt;
            return 0;
        }
    }
}