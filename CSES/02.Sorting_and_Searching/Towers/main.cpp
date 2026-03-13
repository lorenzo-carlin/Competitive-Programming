#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
 
    vector<int> tops;
 
    for(int i = 0; i < n; ++i)
    {
        if(tops.empty() || v[i] >= tops.back()) tops.push_back(v[i]);
        else
        {
            int l = 0, r = tops.size()-1;
            while(l < r)
            {
                int m = (l + r) / 2;
                if(v[i] >= tops[m]) l = m+1;
                else r = m;
            }
            tops[l] = v[i];
        }
    }
 
    cout << tops.size() << "\n";
}
