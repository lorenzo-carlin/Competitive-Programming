#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    if(n % 2)
    {
        cout << "still running\n";
    } else
    {
        bool time = false;
        int ans = 0;
        int prev = 0;
        while(n--)
        {
            int a; cin >> a;
            if(time)
            {
                ans += (a - prev);
            }
            prev = a;
            time = !time;
        }
        cout << ans << "\n";
    }
}