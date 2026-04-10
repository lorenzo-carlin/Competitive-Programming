#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    multiset<int> s;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }

    vector<int> ans, toSort;
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        if(s.lower_bound(x) == s.begin())
        {
            ans.push_back(x);
        } else
        {
            toSort.push_back(x+1);
            s.insert(x+1);
        }
        s.erase(s.find(x));
    }

    sort(begin(toSort), end(toSort));
    for(int el: ans) cout << el << " ";
    for(int el: toSort) cout << el << " ";
    cout << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
