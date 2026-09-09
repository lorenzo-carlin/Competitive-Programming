#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    int interrogate[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> interrogate[i];
    }
    bool visit[n];
    for(int i = 0; i < n; ++i)
    {
        visit[i] = false;
    }
    int ans = 0;
    int house = 1;
    while(!visit[house-1])
    {
        if(house == k)
            break;
        visit[house-1] = true;
        house = interrogate[house-1];
        ans++;
    }
    if(house == k)
        cout << ans;
    else
        cout << -1;
    return 0;
}