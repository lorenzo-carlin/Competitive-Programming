#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5;
int h[MAX];
vector<int> dp(MAX, -1);
int n;

int frog_1(int num)
{
    if(dp[num] != -1)
    {
        return dp[num];
    }
    if(num == n-1)
    {
        dp[num] = 0;
        return dp[num];
    }
    if(num == n-2)
    {
        dp[num] = abs(h[n-2]-h[n-1]);
        return dp[num];
    }
    dp[num] = min(frog_1(num+2)+abs(h[num]-h[num+2]), frog_1(num+1)+abs(h[num]-h[num+1]));
    return dp[num];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    cout << frog_1(0);
}