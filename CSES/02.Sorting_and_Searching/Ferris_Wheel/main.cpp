#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    deque<int> v(n);
    for(auto &i:v) cin >> i;

    sort(v.rbegin(), v.rend());

    int ans = 0;
    int curr;
    while(!v.empty())
    {
        curr = v.front();
        v.pop_front();
        if(!v.empty() && curr + v.back() <= x)
        {
            curr += v.back();
            v.pop_back();
        }
        ans++;
    }

    cout << ans << "\n";
}