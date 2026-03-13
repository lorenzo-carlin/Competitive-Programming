// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// vector<vector<int>> adj;
// int mx = 0, ind = -1;

// void dfs(int c, int p, int dist)
// {
//     if(dist > mx)
//     {
//         mx = dist;
//         ind = c;
//     }
//     for(auto el: adj[c])
//     {
//         if(el != p) dfs(el, c, dist+1);
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n; cin >> n;
//     adj.resize(n);

//     for(int i = 0; i < n-1; ++i)
//     {
//         int a, b; cin >> a >> b;
//         a--; b--;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     dfs(0, -1, 0);
//     int tmp = ind;
//     mx = 0, ind = -1;

//     dfs(tmp, -1, 0);
//     cout << mx << "\n";
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> tree, adj;
vector<int> ord;

void dfs(int c, int p)
{
    ord.push_back(c);
    for(auto el: tree[c])
    {
        if(el != p)
        {
            adj[c].push_back(el);
            dfs(el, c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    tree.resize(n+1);   // all edges
    adj.resize(n+1);    // oriented edges

    for(int i = 0; i < n-1; ++i)
    {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);          // create an order of visiting nodes
    reverse(ord.begin(), ord.end());

    vector<int> toLeaf(n+1), maxLength(n+1);

    for(int i = 0; i < n; ++i)
    {
        int mx = 0;
        for(auto el: adj[ord[i]]) mx = max(mx, toLeaf[el]+1);
        toLeaf[ord[i]] = mx;
    }
    for(int i = 0; i < n; ++i)
    {
        int mx1 = 0, mx2 = 0;
        for(auto el: adj[ord[i]])
        {
            if(toLeaf[el]+1 > mx2 || toLeaf[el]+1 > mx1)
            {
                mx1 = max(mx2, mx1);
                mx2 = toLeaf[el]+1;
            }
        }
        maxLength[ord[i]] = mx1 + mx2;
    }
    int mx = 0;
    for(int i = 1; i <= n; ++i)
    {
        mx = max(mx, maxLength[i]);
    }

    cout << mx << "\n";
}