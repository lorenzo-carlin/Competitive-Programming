#include <bits/stdc++.h>
using namespace std;

int fib[30];

void precalculate()
{
    fib[0] = fib[1] = 1;
    for(int i = 2; i <= 29; ++i)
    {
        fib[i] = fib[i-1]+fib[i-2];
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    
    precalculate();

    string s;
    bool cond = false;
    for(int i = 29; i >= 0; i--)
    {
        if(fib[i] <= n)
        {
            n -= fib[i];
            s.push_back('1');
            cond = true;
        } else if(cond)
        {
            s.push_back('0');
        }
    }

    reverse(s.begin(), s.end());

    cout << s << "\n";
}