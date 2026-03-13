#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &i:v) cin >> i;
        int ind = 0, mx = 0, curr = 0;
        int i = 0;
        while(i < n)
        {
            curr++;
            if(v[i] == 0)
            {
                ind = i;
                break;
            }
            i++;
        }
        i++;
        if(i == n+1)
        {
            mx = n;
        }
        while(i < n)
        {
            if(v[i] == 1)
            {
                curr++;
            }
            if(v[i] == 0 || i == n-1)
            {
                if(curr > mx)
                {
                    mx = curr;
                }
                curr = i - ind;
                ind = i;
            }
            i++;
        }
        cout << "Case #" << x << ": " << mx << "\n";
    }
}