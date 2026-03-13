#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    queue<pair<int,pair<int,int>>> q;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int a; cin >> a;
            if(a != -1)
            {
                ans++;
                q.push({i,{j,a}});
            }
        }
    }
    cout << ans << "\n";
    while(!q.empty())
    {
        cout << q.front().first << " " << q.front().second.first << " " << q.front().second.second << "\n";
        q.pop();
    }
}