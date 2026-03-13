#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    bool cond = true;

    int n, l; cin >> n >> l;
    vector<char> sol(n, '?');

    string s; cin >> s;
    for(int i = 0; i < s.size(); ++i)
    {
        if(isdigit(s[i]))
        {
            int p = s[i]-'0';
            char opp = s[s.size()-(i+1)];
            if(opp == s[i]) continue;
            if(sol[p] == '?' || sol[p] == opp)
            {
                sol[p] = opp;
            } else
            {
                cond = false;
                break;
            }
        }
    }

    string ans;
    for(int i = 0; i < n; ++i)
    {
        if(sol[i] == '?') cond = false;
        ans += sol[i];
    }
    
    if(!cond)
    {
        cout << "impossibile\n";
    } else
    {
        cout << ans << "\n";
    }
}