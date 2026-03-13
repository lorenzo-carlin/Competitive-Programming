#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    int first[n+1];
    for(int i = n; i >= 0; --i)
    {
        if(i == n)
            first[i] = pow(2, i);
        else
            first[i] = first[i+1] + pow(2, i);
    }

    string s; cin >> s;
    if(s.size() == 0)
    {
        cout << first[0];
        return 0;
    }
    int x = 1, y = 1;
    for(int i = 0; i < s.size(); ++i)
    {
        //cout << x << " " << y << endl;
        if(s[i] == 'R')
            x = x * 2;
        if(s[i] == 'L')
            x = x * 2 - 1;
        y++;
    }

    //cout << x << " " << y << endl;
    int num = first[y-1] - (x-1);
    cout << num;
}