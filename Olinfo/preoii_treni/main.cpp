#include <bits/stdc++.h>
using namespace std;

int tempo_massimo(int N, int a[], int b[])
{
    int dp[N+1];
    for(int i = 0; i <= N; ++i)
    {
        if(i == 0)
            dp[i] = 0;
        if(i == 1)
            dp[i] = max(a[i-1], b[i-1]);
        if(i > 1)
            dp[i] = max(dp[i-2]+b[i-1], dp[i-1]+a[i-1]);
    }
    return dp[N];
}

/* Uncomment if you wanto to run the code

int main()
{
    int n;
    FILE *in = stdin, *out = stdout;
    assert(fscanf(in, "%d", &n) == 1);

    int *a = (int*)calloc(n, sizeof(int));
    int *b = (int*)calloc(n, sizeof(int));

    for(int i=0; i<n; i++){
      assert(fscanf(in, "%d", a + i) == 1);
      assert(fscanf(in, "%d", b + i) == 1);
    }

    int answ = tempo_massimo(n, a, b);
    fprintf(out, "%d\n", answ);

    free(a);
    free(b);

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}*/