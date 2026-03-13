#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    multiset<int> pr;
    map<int,int> mp;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        pr.insert(-a);
        mp[-a]++;
    }

    for(int i = 0; i < m; ++i)
    {
        int a; cin >> a;
        auto it = pr.lower_bound(-a);
        if(it == pr.end())
        {
            cout << "-1\n";
            continue;
        }
        int ans = *it;
        mp[ans]--;
        if(mp[ans] == 0)
        {
            pr.erase(ans);
        }
        cout << -ans << "\n";
    }
}