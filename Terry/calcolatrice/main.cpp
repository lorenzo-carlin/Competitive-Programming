#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        ll n; cin >> n;
        ll sol = 1;
        while(n != 2 && n != 1)
        {
            if(n % 2 == 1)
            {
                n++;
            } else
            {
                n/=2;
            }
            sol++;
        }

        cout << "Case #" << cas << ": " << sol << "\n";
    }




    return 0;
}