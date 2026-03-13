#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    set<char> t;
    for(auto el:s) t.insert(el);
    if(t.size() == s.size())
    {
        cout << 1 << "\n";
    } else
    {
        cout << 0 << "\n";
    }
}