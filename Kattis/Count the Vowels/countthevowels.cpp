#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; getline(cin, s);
    int ans = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            ans++;
        }
    }
    cout << ans << "\n";
}