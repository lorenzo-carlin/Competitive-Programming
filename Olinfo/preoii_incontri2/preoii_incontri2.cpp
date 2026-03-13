#include <bits/stdc++.h>
using namespace std;

bool visita(int N, int A[])
{
    int ind_g = 0, ind_e = N-1;
    int tmp = 0;
    bool used = false;
    for(int i = 0; i < N; ++i)
    {
        tmp = A[ind_g];
        int cnt = 0;
        while(cnt < tmp)
        {
            if(A[ind_e] <= (tmp-cnt))
            {
                cnt += A[ind_e];
                ind_e--;
                used = false;
            } else if(A[ind_e] > (tmp-cnt))
            {
                A[ind_e] -= (tmp-cnt);
                cnt = tmp;
                used = true;
            }
        }
        ind_g++;
        if((ind_g == ind_e) && (!used))
        {
            return true;
        }
    }
    return false;
}
