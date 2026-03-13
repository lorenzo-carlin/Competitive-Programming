#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    multiset<int> s;
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        auto it = s.lower_bound(a);
        if(it == s.end())
        {
            s.clear();
        } else if(it != s.begin())
        {
            s.erase(s.begin(), it);
        }
        s.insert(a);
    }
    cout << s.size();
}