#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;
    map<int,int> mp;

    int n, x; cin >> n >> x;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        s.insert(a);
        mp[a]++;
    }

    for(auto el: s)
    {
        int dif = (el - x);
        if(dif == el && mp[el] > 1)
        {
            cout << "Yes\n";
            return 0;
        } else if(s.count(dif) > 0)
        {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}