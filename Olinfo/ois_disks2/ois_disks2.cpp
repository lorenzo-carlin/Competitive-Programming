#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t; cin >> n >> t;

    int h = 0;
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        h += a;
        if(h >= t)
        {
            cout << i-1 << "\n";
            return 0;
        }
        h = 0;
        h += (24 - b);
    }

    cout << -1 << "\n";
}