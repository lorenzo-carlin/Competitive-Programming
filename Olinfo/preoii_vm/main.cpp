#include <iostream>
#include <vector>
using namespace std;

long long aggiorna(int N, vector<int> A, vector<int> B)
{
    long long ans = 0;
    long long lim = A[N-1];
    long long i = N-2;
    while(i >= 0)
    {
        long long dif = lim - A[i];
        ans += dif/B[i];
        lim -= dif%B[i];
        i--;
    }
    return ans;
}