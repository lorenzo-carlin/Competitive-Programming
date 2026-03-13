#include <bits/stdc++.h>
using namespace std;

int find(int num, vector<int> &father)
{
    if(father[num] != num)
    {
        father[num] = find(father[num], father);
    }
    return father[num];
}

void unite(int a, int b, vector<int> &father)
{
    int rA = find(a, father);
    int rB = find(b, father);

    father[rA] = rB;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<int> father(n);
    for(int i = 0; i < n; ++i)
    {
        father[i] = i;
    }

    for(int i = 0; i < m; ++i)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == '?')
        {
            if(find(a, father) == find(b, father))
            {
                cout << "yes\n";
            } else
            {
                cout << "no\n";
            }
        } else
        {
            unite(a, b, father);
        }
    }
}