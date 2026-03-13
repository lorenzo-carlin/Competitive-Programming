#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int a = 0, b = 0;
    for(int i = 0; i < s.size()/2; ++i)
    {
        char c = s[2*i];
        int r = s[2*i+1];
        if(c == 'A')
        {
            a += r;
        } else
        {
            b += r;
        }
    }
    if(a > b)
    {
        cout << "A\n";
    } else
    {
        cout << "B\n";
    }
}