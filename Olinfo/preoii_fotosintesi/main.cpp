#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int fotosintesi(int n, string s)
{
    vector<int> countA(n+1, 0), countB(n+1, 0), countC(n+1, 0);
    for(int i = 0; i < n; ++i)
    {
        countA[i+1] = countA[i];
        countB[i+1] = countB[i];
        countC[i+1] = countC[i];
        if(s[i] == 'A') countA[i+1]++;
        if(s[i] == 'B') countB[i+1]++;
        if(s[i] == 'C') countC[i+1]++;
    }

    map<pair<int,int>,int> mp;
    for(int i = 0; i < n; ++i)
    {
        pair<int,int> tmp = {countA[i+1]-countB[i+1], countA[i+1]-countC[i+1]};
        mp[tmp] = i;
    }

    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        pair<int,int> tmp = {countA[i+1]-countB[i+1], countA[i+1]-countC[i+1]};
        mx = max(mx, mp[tmp]-i);
    }

    return mx;
}
