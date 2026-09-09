#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<bool> exp(n, false);
    int t;
    for(int i = 0; i < n; ++i)
    {
        cin >> t;
        if(t == 1)
        {
            exp[i] = true;
        }
    }
    int cnt = 0;
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        if(exp[a] && exp[b]) cnt++;
    }
    cout << cnt << "\n";
}