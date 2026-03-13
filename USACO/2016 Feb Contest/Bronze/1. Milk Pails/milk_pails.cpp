#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m; cin >> x >> y >> m;

    set<int> s;
    s.insert(0);

    for(auto el: s)
    {
        if(el+x <= m) s.insert(el+x);
        if(el+y <= m) s.insert(el+y);
    }

    auto it = s.end(); it--;
    cout << *it << "\n";
}