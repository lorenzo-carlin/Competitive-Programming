#include <bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    char prev = '?';
    for(auto el: s)
    {
        if(el == prev) return false;
        prev = el;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;
    if(solve(s))
    {
        cout << "Yes\n";
    } else
    {
        cout << "No\n";
    }
}