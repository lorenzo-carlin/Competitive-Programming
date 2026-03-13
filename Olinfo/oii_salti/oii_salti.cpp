#include <bits/stdc++.h>
using namespace std;

int maxPowof2(int n)
{
    int ans = 0;
    for(int i = n; i >= 1; --i)
    {
        if((i & (i-1)) == 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    int cnt = 0;
    while(n > 0)
    {
        n -= maxPowof2(n);
        cnt++;
    }
    cout << cnt << "\n";
}