#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    multiset<int> pos;
    multiset<int> neg;
    queue<int> q;
    map<int,int> mp;

    int ans = 1e9;

    for(int i = 0; i < m; ++i)
    {
        int a; cin >> a;
        mp[a]++;
        q.push(a);
        pos.insert(a);
        neg.insert(-a);
    }

    int mn = *pos.begin();
    int mx = -(*neg.begin());
    if((mx - mn) < ans)
    {
        ans = (mx - mn);
    }
    mp[q.front()]--;
    if(mp[q.front()] == 0)
    {
        pos.erase(q.front());
        neg.erase(-q.front());
    } 
    q.pop();

    for(int i = m; i < n; ++i)
    {
        int a; cin >> a;
        mp[a]++;
        q.push(a);
        pos.insert(a);
        neg.insert(-a);
        int mn = *pos.begin();
        int mx = -(*neg.begin());
        if((mx - mn) < ans)
        {
            ans = (mx - mn);
        }
        mp[q.front()]--;
        if(mp[q.front()] == 0)
        {
            pos.erase(q.front());
            neg.erase(-q.front());
        } 
        q.pop();
    }
    cout << ans << "\n";
}