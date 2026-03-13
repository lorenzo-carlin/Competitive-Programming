#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int l = 1, r = 1e9;
    while(l != r)
    {
        int m = (l + r) / 2;
        cout << "? " << m << "\n";
        cout << flush;

        string s; cin >> s;
        if(s == "YES") l = m+1;
        else r = m;
    }

    cout << "! " << l << "\n";
    cout << flush;
}
