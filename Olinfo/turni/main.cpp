#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k, n; cin >> k >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int sol = 0;
    pair<int,int> curr = {-1, -1};
    while(curr.second != k-1)
    {
        pair<int,int> mx = {-1, -1};
        for(int i = 0; i < n; ++i)
        {
            if(v[i].first > curr.first && v[i].first <= curr.second+1 && v[i].second > mx.second)
            {
                mx = v[i];
            }
        }
        curr = mx;
        sol++;
    }

    cout << sol << "\n";
}