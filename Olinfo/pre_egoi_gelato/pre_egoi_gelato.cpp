#include <bits/stdc++.h>
using namespace std;

int presta(int N, int C, vector<int> P)
{
    sort(P.rbegin(), P.rend());
    int ans = 0, sum = 0, i = 0;
    while(sum < C)
    {
        sum += P[i];
        ans++;
    }
    return ans;
}