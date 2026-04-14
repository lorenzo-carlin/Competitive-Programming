#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    set<int> s;
    for(int i = 0, a; i < n; ++i)
    {
        cin >> a;
        s.insert(a);
    }

    if((s.size() == 1 && !s.count(0)) || (s.size() == 2 && s.count(-1) && !s.count(0))) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
