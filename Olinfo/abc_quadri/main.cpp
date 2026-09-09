#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int quadri(int N, ll M, int V[])
{
    ll sum = 0;
    int l = 0, r = 0;

    while(r < N && sum + V[r] <= M)
    {
        sum += V[r];
        r++;
    }
    int mn = r - l;

    while(r < N)
    {
        sum -= V[l];
        l++;
        while(r < N && sum + V[r] <= M)
        {
            sum += V[r];
            r++;
        }
        mn = min(mn, r - l);
    }
    return mn;
}