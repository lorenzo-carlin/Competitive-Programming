#include <bits/stdc++.h>
using namespace std;

int numberDivisors(int num)
{
    int cnt = 0;
    int ind = 2;
    while(num != 1)
    {
        if(num % ind == 0)
        {
            num /= ind;
            cnt++;
        } else
        {
            ind++;
        }
    }
    return cnt;
}

int main()
{
    int n; cin >> n;
    int ans = numberDivisors(n);
    cout << ans+1 << "\n";
}