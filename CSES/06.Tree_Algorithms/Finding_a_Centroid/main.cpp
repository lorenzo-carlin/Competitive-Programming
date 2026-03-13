#include <bits/stdc++.h>
using namespace std;
 
int N;
vector<vector<int>> adj;
vector<int> sz;
 
void dfs(int n, int p)
{
  sz[n] = 1;
  for(int &i: adj[n])
  {
    if(i == p) continue;
    dfs(i, n);
    sz[n] += sz[i];
  }
}
 
int find_centroid(int n, int p)
{
  for(int &i: adj[n])
  {
    if(i == p) continue;
    if(sz[i]*2 > N) return find_centroid(i, n);
  }
  return n;
}
 
int main()
{
  int n; cin >> n;
  N = n;
  adj.resize(n);
  sz.resize(n);
  for(int i = 0; i < n-1; ++i)
  {
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0,-1);
  cout << find_centroid(0, -1)+1 << "\n";
}