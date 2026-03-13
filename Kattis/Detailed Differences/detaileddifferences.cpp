#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int t; cin >> t;
    while(t--)
    {
        string a, b; cin >> a >> b;
        cout << a << "\n";
        cout << b << "\n";
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] == b[i])
            {
                cout << ".";
            } else
            {
                cout << "*";
            }
        }
        cout << "\n\n";
    }
}