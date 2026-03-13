#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, m; cin >> h >> m;
    h -= 1;
    m += 15;
    if(m >= 60)
    {
        h += 1;
        m -= 60;
    }
    if(h == -1)
        h = 23;
    cout << h << " " << m << "\n";
}