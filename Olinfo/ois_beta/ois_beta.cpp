#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    unordered_map<int,int> mp;

    int a;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        mp[a]++;
    }

    int cnt = 0;
    for(auto el: mp)
    {
        if(el.second > 1) cnt++;
    }

    if(cnt <= 1) cout << "NO\n";
    else cout << "YES\n";
}