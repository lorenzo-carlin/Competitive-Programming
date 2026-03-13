#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    bool cond = false;
    for(int i = 0; i < s.size()-1; ++i)
    {
        if(s[i] == 's' && s[i+1] == 's')
        {
            cond = true;
        }
    }
    if(cond) cout << "hiss\n";
    if(!cond) cout << "no hiss\n";
}