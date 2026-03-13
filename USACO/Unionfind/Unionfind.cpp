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
    int n; cin >> n;
    vector<int> father(n);
    for(int i = 0; i < n; ++i)
    {
        father[i] = i;
    }

    int q; cin >> q;
    int t, u, v;
    while(q--)
    {
        cin >> t >> u >> v;
        if(!t)
        {
            unite(u, v, father);
        } else
        {
            if(find(u, father) == find(v, father))
            {
                cout << 1 << "\n";
            } else
            {
                cout << 0 << "\n";
            }
        }
    }
}