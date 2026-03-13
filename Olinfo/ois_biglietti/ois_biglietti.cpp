#include <bits/stdc++.h>
using namespace std;

int compra(int N, int M, int A, int B)
{
    int tot = 0;
    while(N > 0)
    {
        if(N <= M)
        {
            if(N * A < B)
            {
                tot = tot + N * A;
                N = N - M;
            } else
            {
                tot = tot + B;
                N = N - M;
            }
        } else
        {
            if(M * A < B)
            {
                tot = tot + M * A;
                N = N - M;
            } else
            {
                tot = tot + B;
                N = N - M;
            }
        }
    }
    return tot;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, A, B; cin >> N >> M >> A >> B;
    int tot = compra(N, M, A, B); cout << tot << "\n";
}
