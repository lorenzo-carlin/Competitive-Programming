#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int n; cin >> n;

        vector<int> a(n);
        for(auto &i:a) cin >> i;
        vector<int> b(n);
        for(auto &i:b) cin >> i;
        int tot = 0;
        for(int i = 0; i < n; ++i)
        {
            if(b[i] < a[i]) tot++;
        }
        cout << "Case #" << x << ": " << tot << "\n";
    }
}