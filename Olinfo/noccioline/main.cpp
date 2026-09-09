#include <bits/stdc++.h>
using namespace std;

int ContaOperazioni(int N, int K, int* secchi)
{
    int sum = 0, op = 0;
    for(int i = 0; i < N; ++i)
    {
        sum += secchi[i];
        if(secchi[i] < K)
        {
            op += (K-secchi[i]);
        }
    }
    op += max(sum-N*K, 0);
    return op;
}