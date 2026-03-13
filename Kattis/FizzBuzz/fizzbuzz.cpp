#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, n; cin >> x >> y >> n;
    for(int i = 1; i <= n; ++i)
    {
        bool cond1 = false, cond2 = false;
        if(i % x == 0)
        {
            cond1 = true;
        }
        if(i % y == 0)
        {
            cond2 = true;
        }
        if(cond1 && cond2)
        {
            cout << "FizzBuzz\n";
        } else if(cond1)
        {
            cout << "Fizz\n";
        } else if(cond2)
        {
            cout << "Buzz\n";
        } else
        {
            cout << i << "\n";
        }
    }
}