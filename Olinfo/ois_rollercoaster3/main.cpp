#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    int cur = 0, h = 0, ans = 0;

    if(s[0] == 'H')
    {
        ans = 1;
        cur = 10;
    }

    for(int i = 0; i < n; i++)
    {
        if(i == 0 && s[i] == 'H') continue;

        if(s[i] == 'H') h++;
        if(s[i] == 'D') cur += 9;
        if(s[i] == 'B') cur += 10;
        if(s[i] == 'U') cur -= 11;

        if(cur <= 0)
        {
            int needed = (0 - cur + 10) / 10;
            if(h < needed)
            {
                cout << -1 << "\n";
                return 0;
            } else
            {
                h -= needed;
                ans += needed;
                cur += 10*needed;
            }
        }
    }

    cout << ans << "\n";
}
