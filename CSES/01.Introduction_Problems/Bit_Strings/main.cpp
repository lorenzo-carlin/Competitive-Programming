#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    long long mod = 1000000007;
    long long ris = 1;
    int base = 2;
    int esp;
    for(esp = 0; esp < n; ++esp)
    {
        ris = (ris * base) % mod;
    }
    cout << ris;
    return 0;
}