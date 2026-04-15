#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> cities(n);
    for(auto &i: cities) cin >> i;
    vector<int> towers(m);
    for(auto &i: towers) cin >> i;

    int c = 0, t = 0, mx = 0;
    for(; c < n; c++)
    {
        while(t < m-1 && (abs(cities[c]-towers[t]) >= abs(cities[c]-towers[t+1]))) t++;
        mx = max(mx, abs(cities[c]-towers[t]));
    }

    cout << mx << "\n";
}
