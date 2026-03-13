#include <bits/stdc++.h>
using namespace std;

int main()
{
    float tot = 0;
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        float a, b; cin >> a >> b;
        tot += (a*b);
    }
    cout << floor(tot*1000) / 1000 << "\n";
}