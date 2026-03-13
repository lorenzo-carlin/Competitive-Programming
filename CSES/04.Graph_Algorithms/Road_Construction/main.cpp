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

void unite(int a, int b, vector<int> &father, vector<int> &size)
{
    int rA = find(a, father);
    int rB = find(b, father);
    father[rA] = rB;
    size[rB] += size[rA];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<int> father(n);
    vector<int> size(n, 1);
    for(int i = 0; i < n; ++i)
    {
        father[i] = i;
    }

    int comp = n;
    int mx_size = 1;
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        if(find(a, father) != find(b, father))
        {
            comp--;
            unite(a, b, father, size);
            if(size[find(a, father)] > mx_size)
            {
                mx_size = size[find(a, father)];
            }
        }
        cout << comp << " " << mx_size << "\n";
    }
}