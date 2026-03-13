#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    int cnt = 0, res = 0;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        int div = a / k;
        if(a == 11*k)
        {
            div == 11;
        } else if(div > 10)
        {
            div = 10;
        }
        cnt += div;
        res += (a - (div * k));
    }
    cout << cnt << " " << res << "\n";
}