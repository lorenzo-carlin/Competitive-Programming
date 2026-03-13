#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> used;
string s;
set<string> sol;

void solve(string tmp)
{
    if(tmp.size()==n)
    {
        sol.insert(tmp);
        return;
    }
    for(int i = 0; i < n; ++i)
    {
        if(used[i] == false)
        {
            tmp.push_back(s[i]);
            used[i] = true;
            solve(tmp);
            tmp.pop_back();
            used[i] = false;
        }
    }
    return;
}

int main()
{
    cin >> s;
    n = s.size();
    for(int i = 0; i < s.size(); ++i)
    {
        used.push_back(false);
    }
    solve("");
    cout << sol.size() << "\n";
    for(auto el:sol)
    {
        cout << el << "\n";
    }
}