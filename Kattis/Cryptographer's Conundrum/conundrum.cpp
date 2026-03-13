#include <bits/stdc++.h>
using namespace std;

string def = "PER";

int main()
{
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] != def[i%3])
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
}