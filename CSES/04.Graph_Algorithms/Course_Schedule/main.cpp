#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> ord, tag;
bool cycle = false;
 
void dfs(int n)
{
    tag[n] = 1;
 
    for(int v: adj[n])
    {
        if(tag[v] == 1)
        {
            cycle = true;
        } else if(tag[v] == 0)
        {
            dfs(v);
        }
    }
 
    tag[n] = 2;
    ord.push_back(n);
}
 
int main() {
    int n; cin >> n;
    int m; cin >> m;
    adj.resize(n);
    tag.resize(n, 0);
 
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
    }
 
    for(int i = 0; i < n; ++i)
    {
        if(tag[i] == 0)
        {
            dfs(i);
        }
    }
 
    if(cycle)
    {
        cout << "IMPOSSIBLE\n";
    } else
    {
        reverse(begin(ord), end(ord));
 
        for(int el: ord)
        {
            cout << el+1 << " ";
        }
        cout << "\n";
    }  
}
