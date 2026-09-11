#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int k; cin >> k;
        int a, b, c, d; cin >> a >> b >> c >> d;
        int tot;
        while(k--)
        {
            if(a != 0)
            {
                a--; d++;
            } else if(b != 0)
            {
                b--; d++;
            } else if(c != 0)
            {
                c--; d++;
            }
            tot = a + (2 * b) + (3 * c) + (4 * d);
        }
        cout << "Case #" << i << ": " << tot << "\n";
    }
}