#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<int> v(n);

    auto time = [&] (string s) -> int
    {
        int h = (((int) s[0]) - ((int) '7'));
        int m = (((int) s[2]) - ((int) '0')) * 10 + (((int) s[3]) - ((int) '0'));
        return (60*h + m);
    };

    for(int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        v[i] = time(s);
    }

    int mn = 2;
    for(int i = 0; i < n-2; i++)
    {
        if(v[i+2] - v[i] <= 10) mn = min(mn, 0);
        if(v[i+1] - v[i] <= 10) mn = min(mn, 1);
        if(v[i+2] - v[i+1] <= 10) mn = min(mn, 1);
    }
    if(v[1]-v[0] <= 10) mn = min(mn, 1);

    cout << mn << "\n";
}
