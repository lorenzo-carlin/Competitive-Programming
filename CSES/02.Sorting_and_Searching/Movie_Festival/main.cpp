#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    
    vector<pair<int,int>> v;
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    int sol = 0, curr = 0;
    for(int i = 0; i < n; ++i)
    {
        if(v[i].second >= curr)
        {
            sol++;
            curr = v[i].first;
        }
    }

    cout << sol << "\n";
}