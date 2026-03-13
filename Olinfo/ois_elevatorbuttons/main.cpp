#include <bits/stdc++.h>
using namespace std;

int main()
{
    int lo, hi, pos; cin >> lo >> hi >> pos;
    string s; cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'U')
            pos++;
        else if(s[i] == 'D')
            pos--;
        else
            pos = 0;

        if(pos < lo || pos > hi)
        {
            cout << "error\n";
            return 0;
        }
    }

    cout << pos << "\n";
}
