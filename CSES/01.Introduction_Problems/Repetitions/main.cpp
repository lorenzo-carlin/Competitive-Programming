#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int len = s.length();
    int mx = 0;
    int rep = 0;
    for(int i = 0; i < len; ++i)
    {
        if(s[i] == s[i-1])
        {
            rep++;
            if(rep > mx)
            {
                mx = rep;
            }
        } else
        {
            rep = 0;
        }
    }
    cout << mx+1;
    return 0;
}