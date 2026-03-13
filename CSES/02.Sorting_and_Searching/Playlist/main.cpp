#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    set<int> s;
    int l = 0, r = 0, mx = 0;
    for(; r < n; ++r)
    {
        if(s.count(v[r]))
        {
            mx = max(mx, r-l);
            while(v[l] != v[r])
            {
                s.erase(v[l]);
                l++;
            }
            l++;
        } else
        {
            s.insert(v[r]);
        }
    }
    mx = max(mx, r-l);

    cout << mx << "\n";
}