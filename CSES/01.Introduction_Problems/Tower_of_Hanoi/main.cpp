#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<pair<int,int>> sol;
 
void TowerOfHanoi(int n, int from_rod, int to_rod, int aux_rod)
{
    if(n == 0) return;
 
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    sol.push_back({from_rod, to_rod});
    // cout << from_rod << " " << to_rod << "\n";
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
    TowerOfHanoi(n, 1, 3, 2);
 
    cout << sol.size() << "\n";
    for(auto el: sol) cout << el.first << " " << el.second << "\n";
}
