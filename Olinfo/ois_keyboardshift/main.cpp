#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string f1 = "qwertyuiop";
    string f2 = "asdfghjkl";
    string f3 = "zxcvbnm";
    int N;
    cin >> N;
    string s;
    cin >> s;
    for(int i = 0; i < N; ++i)
    {
        int fi1 = f1.find(s[i]);
        int fi2 = f2.find(s[i]);
        int fi3 = f3.find(s[i]);
        if(fi1 < f1.size())
        {
            cout << f1[fi1+1];
        } else if(fi2 < f2.size())
        {
            cout << f2[fi2+1];
        } else if(fi3 < f3.size())
        {
            cout << f3[fi3+1];
        }
    }
    return 0;
}