#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<int,int> mp;

    int n; cin >> n;
    while(n--)
    {
        int a, b; cin >> a >> b;
        mp[a] += b;
    }
    
    int mx = -1, mx_ind;
    for(auto el: mp)
    {
        if(el.second > mx)
        {
            mx = el.second;
            mx_ind = el.first;
        }
    }
    cout << mx_ind << " " << mx << "\n";
}