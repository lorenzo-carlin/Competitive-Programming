#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    sort(v.begin(), v.end());
    int ans = 0, i = 0;
    while(i < n)
    {
        if(v[i] + v[i+1] <= x)
        {
            i += 2;
        } else
        {
            i++;
        }
        ans++;
    }
    cout << ans << "\n";
}