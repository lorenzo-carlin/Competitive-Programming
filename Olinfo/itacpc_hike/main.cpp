#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int cur = 3000;
    for(int i = 0, a; i < n; i++)
    {
        cin >> a;
        cur += a;
    }

    cout << cur << "\n";
}
