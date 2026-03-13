#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n; cin >> n;
    char c; cin >> c;

    map<char,int> dom;
    map<char,int> notdom;

    dom['A'] = 11;  notdom['A'] = 11;
    dom['K'] = 4;   notdom['K'] = 4;
    dom['Q'] = 3;   notdom['Q'] = 3;
    dom['J'] = 20;  notdom['J'] = 2;
    dom['T'] = 10;  notdom['T'] = 10;
    dom['9'] = 14;  notdom['9'] = 0;
    dom['8'] = 0;   notdom['8'] = 0;
    dom['7'] = 0;   notdom['7'] = 0;

    int ans = 0;
    while(n--)
    {
        for(int i = 0; i < 4; ++i)
        {
            char a, b; cin >> a >> b;
            if(b == c)
            {
                ans += dom[a];
            } else
            {
                ans += notdom[a];
            }
        }
    }

    cout << ans << "\n";
}