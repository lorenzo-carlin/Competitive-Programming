#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s;
        for(int i = 0; i < 64; ++i)
        {
            char c; cin >> c;
            if(c != '.') s += c;
        }
        cout << s << "\n";
    }
}