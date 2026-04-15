#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    map<int,int> mp;
    int l = 0, r = 0;
    int mx_len = 0, L = -1, R = -1;
    for(; l < n; l++)
    {
        while(r < n && mp.size() <= k)
        {
            mp[v[r]]++;

            if(r-l+1 > mx_len && mp.size() <= k)
            {
                mx_len = r-l+1;
                L = l;
                R = r;
            }

            r++;
        }

        mp[v[l]]--;
        if(mp[v[l]] == 0) mp.erase(v[l]);
    }

    cout << L+1 << " " << R+1 << "\n";
}
