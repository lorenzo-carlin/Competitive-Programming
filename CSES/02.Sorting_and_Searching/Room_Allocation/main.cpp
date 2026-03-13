#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<pair<int,int>> arr, dep;
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        arr.push_back({a, i+1});
        dep.push_back({b, i+1});
    }

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int curr = 1;
    map<int,int> room;
    set<int> available;

    int a = 0, d = 0;
    for(; a < n; a++)
    {
        while(dep[d].first < arr[a].first)
        {
            available.insert(room[dep[d].second]);
            d++;
        }
        if(!available.empty())
        {
            room[arr[a].second] = *available.begin();
            available.erase(available.begin());
        } else
        {
            room[arr[a].second] = curr++;
        }
    }

    cout << curr-1 << "\n";
    for(int i = 1; i <= n; ++i)
    {
        cout << room[i] << " ";
    }
    cout << "\n";
}