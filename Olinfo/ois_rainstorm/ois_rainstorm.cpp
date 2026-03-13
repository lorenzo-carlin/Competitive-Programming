#include <bits/stdc++.h>
using namespace std;

int find(int node, vector<int> &father)
{
    if(father[node] != node)
    {
        father[node] = find(father[node], father);
    }
    return father[node];
}

void unite(int a, int b, vector<int> &father)
{
    int rA = find(a, father);
    int rB = find(b, father);
    if(rand() % 2)
    {
        father[rA] = rB;
    } else
    {
        father[rB] = rA;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    priority_queue<pair<int,pair<int,int>>> q;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        q.push({c,{a,b}});
    }

    vector<int> father(n);
    for(int i = 0; i < n; ++i)
    {
        father[i] = i;
    }

    int mn = INT_MAX;
    while(!q.empty())
    {
        int c = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if(find(x, father) != find(y, father))
        {
            unite(x, y, father);
            mn = c;
        }
    }

    cout << mn << "\n";
}