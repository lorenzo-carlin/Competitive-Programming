#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    map<int,int> mp;

    for(int i = 0; i < 2*n-1; ++i)
    {
        int a; cin >> a;
        mp[a]++;
    }

    for(auto el: mp)
    {
        if(el.second == 1)
        {
            cout << el.first << "\n";
            break;
        }
    }
}