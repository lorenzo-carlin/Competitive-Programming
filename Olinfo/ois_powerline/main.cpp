#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    vector<int> dp(n, 0);
    int mx = -1;
    for(int i = n-1; i >= 0; i--)
    {
        if(v[i] >= mx) mx = v[i];
        else dp[i] = dp[i+1]+1;
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}