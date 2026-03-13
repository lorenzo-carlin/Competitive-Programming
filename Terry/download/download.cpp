#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T; cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        int n, f, c; cin >> n >> f >> c;
        int a = n / f; n = n % f;
        int b = n / c;
        cout << "Case #" << i << ": " << a << " " << b << "\n";
    }
}