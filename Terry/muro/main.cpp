#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int n, q; cin >> n >> q;
        int ind = 0;
        for(int i = 0; i < q; ++i)
        {
            int a; cin >> a;
            if(ind + a > n)
            {
                ind = n - a;
            }
            ind++;
        }
        cout << "Case #" << x << ": " << ind << "\n";
    }
}