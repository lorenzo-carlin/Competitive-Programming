#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    bool valid = false, first = true;
    int cntZero = 0;

    for(int i = 0; i < n-1; i++)
    {
        if(s[i] == '1' && s[i+1] == '1')
        {
            if(!valid && (cntZero & 1) && !first)
            {
                cout << "NO\n";
                return;
            } else if(!valid && (cntZero & 1) && first && s[0] != '0')
            {
                cout << "NO\n";
                return;
            }

            valid = false;
            first = false;
            cntZero = 0;
        } else if(s[i] == '0' && s[i+1] == '0')
        {
            valid = true;
        }

        if(s[i] == '0') cntZero++;
    }

    if(s[n-1] == '0') cntZero++;

    if(valid || (first && s[0] == '0') || (s[n-1] == '0') || (cntZero % 2 == 0) || (cntZero == 0))
    {
        cout << "YES\n";
    } else
    {
        cout << "NO\n";
    }
/*
    if(!valid && (cntZero & 1) && !first && s[n-1] != '0')
    {
        cout << "NO\n";
        return;
    } else if(!valid && (cntZero & 1) && first && s[0] != '0')
    {
        cout << "NO\n";
        return;
    }
    */

    // cout << "YES\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
