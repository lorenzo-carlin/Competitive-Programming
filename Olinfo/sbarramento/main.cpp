#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r; cin >> n >> r;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    int sol = 0;
    for(auto el: x) sol += abs(el - r);
    sort(y.begin(), y.end());
    for(int i = 1; i <= n; ++i) sol += abs(y[i-1] - i);

    cout << sol << "\n";
}