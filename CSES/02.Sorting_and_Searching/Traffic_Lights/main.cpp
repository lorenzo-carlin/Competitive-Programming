#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, n; cin >> x >> n;

    set<int> intervals; intervals.insert(x);
    map<int,int> l; l[x] = x;
    priority_queue<pair<int,int>> q; q.push({x, l[x]});

    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        int ind = *intervals.lower_bound(a);
        intervals.insert(a);
        int left = ind - l[ind];
        l[a] = a - left;
        l[ind] = ind - a;
        q.push({l[a], a});
        q.push({l[ind], ind});

        while(q.top().first != l[q.top().second]) q.pop();
        cout << q.top().first << "\n";
    }
}