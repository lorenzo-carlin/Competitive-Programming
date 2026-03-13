#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int g, p; cin >> g >> p;
    int tot = 0;
    for(int i = 1; i < 400; i++)
    {
        if(g < i)
        {
            tot += g;
            break;
        }
        tot += i;
        g -= (i + p - 1);
        if(g < 0) break;
    }
    cout << tot << "\n";
}