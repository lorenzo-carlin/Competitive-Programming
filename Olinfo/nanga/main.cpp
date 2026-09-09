#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    map<int,int> mp;
    int ind = 5000;
    while(n--)
    {
        int p; cin >> p;
        ind += p;
        mp[ind]++;
    }
    int mx = -1, mx_ind = -1;
    for(auto el: mp)
    {
        if(el.second > mx)
        {
            mx = el.second;
            mx_ind = el.first;
        }
    }
    cout << mx_ind << "\n";
}