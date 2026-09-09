#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> v(n);
    priority_queue<pair<int,int>> q;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        q.push({v[i], i});
    }

    ll tot = 0;
    pair<int,int> l = {0, n}, r = {0, -1};
    while(!q.empty())
    {
        int x = q.top().first;
        int y = q.top().second;
        q.pop();

        if(y > l.second && y < r.second) continue;
        if(y < l.second)
        {
            tot += (ll) (l.second - y) * min(l.first, x);
            l = {x, y};
        }
        if(y > r.second)
        {
            tot += (ll) (y - r.second) * min(r.first, x);
            r = {x, y};
        }
    }

    cout << tot << "\n";
}