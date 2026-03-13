#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        v.push_back({a, i+1});
    }

    sort(v.begin(), v.end());

    vector<pair<int,int>> t;
    for(int i = 0; i < n; ++i)
    {
        int target = x - v[i].first;
        int l = 0, r = n-1;
        for(; l < r; l++)
        {
            while(l < r && v[l].first + v[r].first > target)
            {
                r--;
            }
            if(l < r && v[l].first + v[r].first == target && v[l].second != v[i].second && v[r].second != v[i].second)
            {
                cout << v[l].second << " " << v[r].second << " " << v[i].second << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}