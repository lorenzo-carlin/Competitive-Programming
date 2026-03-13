#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s = "welcome to code jam";
string t;

ll solve(int x, int y)
{
    if(y == t.size()+1)
        return 0;
    if(x == s.size()+1)
        return 0;
    ll ans = 0;
    for(int i = y; i < t.size(); ++i)
    {
        if(t[i] == s[x])
        {
            if(x == s.size()-1)
            {
                ans += 1;
            } else
            {
                ans += solve(x+1, i+1);
            }   
        }
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    cin.ignore();
    for(int x = 1; x <= n; ++x)
    {
        getline(cin, t);
        ll ans = solve(0,0) % 10000;
        cout << "Case #" << x << ": ";
        if(ans < 10)
        {
            cout << "000" << ans << endl;
        } else if(ans < 100)
        {
            cout << "00" << ans << endl;
        } else if(ans < 1000)
        {
            cout << "0" << ans << endl;
        } else
        {
            cout << ans << endl;
        }
        t.clear();
    }
}