#include <bits/stdc++.h>
using namespace std;

int organizza(int N, int X, int Y, vector<int> A, vector<int> B)
{
    map<int,int> mp;
    mp[X] = 0;

    for(int i = 0; i < N; ++i)
    {
        mp[A[i]]--;
        mp[B[i]+1]++;
    }

    int curr = N;
    int mx = 0;

    for(auto x:mp)
    {
        curr += x.second;
        if(x.first >= X && x.first <= Y && curr > mx)
        {
            mx = curr;
        }
    }

    return mx;
}