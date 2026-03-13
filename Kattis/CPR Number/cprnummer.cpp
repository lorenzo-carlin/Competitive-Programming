#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tot = 0;
    int v[10] = {4, 3, 2, 7, 6, 5, 4, 3, 2, 1};
    for(int i = 0; i < 6; ++i)
    {
        char c; cin >> c;
        int num = c - '0';
        tot += (num * v[i]);
    }
    char buf; cin >> buf;
    for(int i = 6; i < 10; ++i)
    {
        char c; cin >> c;
        int num = c - '0';
        tot += (num * v[i]);
    }
    if(tot % 11 == 0)
    {
        cout << "1\n";
    } else
    {
        cout << "0\n";
    }
}