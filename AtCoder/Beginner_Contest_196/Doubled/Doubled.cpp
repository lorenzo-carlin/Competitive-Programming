#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll before(int size)
{
    int half = size/2;
    ll res = 9;
    half--;
    res = res * pow(10, half);
    return res;
}

ll samelen(ll n, string num)
{
    if(num.size() % 2 == 1)
        return 0;
    ll cnt = 0;
    ll prz = pow(10, num.size()/2-1);
    while(prz*pow(10,num.size()/2)+prz <= n)
    {
        prz += 1;
        cnt++;
    }
    return cnt;
}

int main()
{
    ll n; cin >> n;
    string num = to_string(n);
    ll ans = 0;

    // trovo i numeri validi con meno cifre rispetto all'originale
    int len = num.size();
    len--;
    while(len > 0)
    {
        if(len % 2 == 0)
        {
            ans += before(len);
        }
        len--;
    }

    // trovo  i numeri validi con lo stesso numero di cifre dell'originale
    ans += samelen(n, num);

    cout << ans << "\n";
}