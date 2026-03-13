#include <bits/stdc++.h>
using namespace std;

const int M = 100000;
vector<int> v[M];

void inizia(int N, int M)
{
    v[0].resize(N);
    for(int i = 0; i < N ; ++i)
    {
        v[0][i] = i;
    }
}

void sposta(int a, int b)
{
    v[b].push_back(v[a].back());
    v[a].pop_back();
}

int controlla(int a, int i)
{
    return int(v[a].size()) <= i ? -1 : v[a][i];
}
