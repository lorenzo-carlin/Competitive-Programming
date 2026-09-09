#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n*(n-1)/2; ++i)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(c > d) mp[a]+=3;
        if(c < d) mp[b]+=3;
        if(c == d)
        {
            mp[a]+=1;
            mp[b]+=1;
        }
    }

    int mx = 0, mx_ind;
    for(auto el: mp)
    {
        if((el.second > mx) || (el.second == mx && el.first < mx_ind))
        {
            mx = el.second;
            mx_ind = el.first;
        }
    }

    cout << mx_ind << " " << mx << "\n";

}