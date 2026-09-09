#include <bits/stdc++.h>
using namespace std;

int MCD(int a, int b)
{
    int mod = a % b;
    if(mod == 0) return b;
    return MCD(b, mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b; cin >> a >> b;
    int sol1 = a/MCD(a, b);

    int mn = 20;
    while(MCD(a, mn) != 1) mn++;
    cout << sol1 << " " << mn << "\n";
}