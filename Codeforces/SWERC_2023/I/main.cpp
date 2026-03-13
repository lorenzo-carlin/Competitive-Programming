#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll m, n; cin >> m >> n;
    ll A = m, B = n;
    for(int i = 0, c; i < m; i++)
    {
        cin >> c;
        A += c;
    }
    for(int i = 0, c; i < n; i++)
    {
        cin >> c;
        B += c;
    }

    if(A > B) cout << "ALICE\n";
    else if(B > A) cout << "BOB\n";
    else cout << "TIED\n";
}
