#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    int sol = 1;
    for(int i = 2; i*i <= n; ++i)
    {
        int ans = 1;
        while(ans * i <= n) ans *= i;
        sol = max(sol, ans);
    }

    cout << sol << "\n";
}