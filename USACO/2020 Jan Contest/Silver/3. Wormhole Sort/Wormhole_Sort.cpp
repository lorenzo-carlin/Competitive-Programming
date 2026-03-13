#include <bits/stdc++.h>
using namespace std;

struct wormhole
{
    int a, b, width;
};

bool operator < (wormhole &w1, wormhole &w2)
{
    return w1.width < w2.width;
}

int find(int node, vector<int> &father)
{
    if(father[node] != node) father[node] = find(father[node], father);
    return father[node];
}

void unite(int a, int b, vector<int> &father)
{
    int rA = find(a, father), rB = find(b, father);
    father[rA] = rB;
}

int main()
{
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a; a--;
        v[i] = a;
    }

    vector<wormhole> w(m);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        w[i] = {a, b, c};
    }

    sort(w.begin(), w.end());

    int ind = n;
    vector<int> father(n);
    for(int i = 0; i < n; ++i)
    {
        father[i] = i;
    }
    for(int i = 0; i < n; ++i)
    {
        while(find(i, father) != find(v[i], father))
        {
            ind--;
            unite(w[ind].a, w[ind].b, father);
        }
    }

    int sol = (ind == n) ? -1 : w[ind].width;
    cout << sol << "\n";
}