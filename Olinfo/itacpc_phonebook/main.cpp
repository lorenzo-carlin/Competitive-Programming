#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    string s;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if((s.size() == 13 || s.size() == 12) && (s[0] == '+' && s[1] == '3' && s[2] == '9')) ans++;
    }

    cout << ans << "\n";
}
