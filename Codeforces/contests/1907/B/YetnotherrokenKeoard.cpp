#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s; cin >> s;

    stack<int> low, upp;
    set<int> er;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'b' && !low.empty())
        {
            er.insert(low.top());
            low.pop();
        } else if(s[i] == 'B' && !upp.empty())
        {
            er.insert(upp.top());
            upp.pop();
        } else if(isupper(s[i]))
        {
            upp.push(i);
        } else if(islower(s[i]))
        {
            low.push(i);
        }

        if(s[i] == 'b' || s[i] == 'B') er.insert(i);
    }

    string sol;
    for(int i = 0; i < s.size(); ++i)
        if(!er.count(i))
            sol += s[i];
    
    cout << sol << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
