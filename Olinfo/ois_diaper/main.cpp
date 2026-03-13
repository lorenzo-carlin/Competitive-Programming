#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int m = 0, b = 0, f;
    char t;
    int ans = 0;
    for(int i = 0; i < n-1; i++)
    {
        cin >> f >> t;
        if(t == 'M') m += f;
        else b += f;

        if(m >= 50)
        {
            ans++;
            m -= 50;
        } else if(b >= 80)
        {
            ans++;
            b -= 80;
        }
    }
    cin >> f >> t;

    cout << ans << "\n";
}
