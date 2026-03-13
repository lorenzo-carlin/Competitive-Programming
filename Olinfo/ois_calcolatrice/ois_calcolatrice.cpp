#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<char,char> mp;
    mp['0'] = '0';
    mp['1'] = '1';
    mp['2'] = '2';
    mp['3'] = 'x';
    mp['4'] = 'x';
    mp['5'] = '5';
    mp['6'] = '9';
    mp['7'] = 'x';
    mp['8'] = '8';
    mp['9'] = '6';

    string s; cin >> s;
    string rev;
    for(int i = s.size()-1; i >= 0; i--)
    {
        if(mp[s[i]] == 'x')
        {
            cout << s << "\n";
            return 0;
        } else
        {
            rev += mp[s[i]];
        }
    }

    if(rev[0] == '0')
    {
        for(int i = 0; i < rev.size(); ++i)
        {
            rev[i] = '9';
        }
    }
    cout << min(s, rev) << "\n";
}