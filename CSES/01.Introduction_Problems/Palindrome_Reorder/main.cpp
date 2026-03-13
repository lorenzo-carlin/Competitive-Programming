#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    map<char, int> mp;
    for(char el: s)
    {
        mp[el]++;
    }
    string ris;
    char last = '?';
    for(auto el: mp)
    {
        if(el.second % 2 == 1)
        {
            if(last == '?')
            {
                last = el.first;
                for(int i = 0; i < el.second/2; ++i)
                {
                    ris += el.first;
                }
            } else
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
        } else
        {
            for(int i = 0; i < el.second/2; ++i)
            {
                ris += el.first;
            }
        }
    }
    string ris2 = ris;
    reverse(ris2.begin(), ris2.end());
    ris = (last != '?') ? (ris + last) : (ris);
    ris += ris2;
    cout << ris << "\n";
}