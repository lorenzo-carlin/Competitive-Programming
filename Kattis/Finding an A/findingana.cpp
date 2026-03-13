#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a; cin >> a;
    bool cond = false;
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] == 'a')
        {
            cond = true;
        }
        if(cond)
        {
            cout << a[i];
        }
    }
}