#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int rimembra(int n, int k, vector<int> v)
{
    int ans = 0;
    int l = 0, r = 0;
    int contenuti;
    if(v[0] == 0) contenuti = 1;
    else contenuti = 0;
    for(; l < n; l++)
    {
        while(r < n-1 && contenuti <= k)
        {
            r++;
            if(v[r] == 0) contenuti++;
        }

        if(r == n-1 && v[r]==1)
        {
            ans = max(ans, r-l+1);
        } else
        {
            ans = max(ans, r-l);
        }

        if(v[l] == 0) contenuti--;
    }

    return ans;
}