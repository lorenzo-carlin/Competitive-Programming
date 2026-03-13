#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        int n, m; cin >> n >> m;
        vector<int> h(n), d(n);
        for(auto &i: h) cin >> i;
        for(auto &i: d) cin >> i;

        int l = 0, r = 1e8;
        while(l < r)
        {
            int m = (l + r) / 2;
        }
    }
}