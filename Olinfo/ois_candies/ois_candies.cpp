#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    int n; cin >> n;
    vector<LL> s(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    LL ans = 1;
    LL can = 1;
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] != s[i-1])
        {
            can++;
            ans += can;
        } else
        {
            ans += can;
        }
    }
    cout << ans;
    return 0;
}