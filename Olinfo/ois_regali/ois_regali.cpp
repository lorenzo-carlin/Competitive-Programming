#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define MAXQ 1000

int compra(int N, int Q, int* G[]) {
    int mx = 0;
    int curr = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = i+1; j < N; ++j)
        {
            // calcolo la distanza di due qualità
            curr = 0;
            for(int x = 0; x < Q; ++x)
            {
                if(G[i][x] == G[j][x])
                {
                    curr++;
                } else
                {
                    if(curr > mx) mx = curr;
                    break;
                }
            }
        }
    }
    return mx;
}


int* G[MAXN];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    FILE *fr, *fw;
    int N, Q, i, j;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &Q));
    for(i=0; i<N; i++) {
        G[i] = (int*)malloc(Q*sizeof(int));
        for (j=0; j<Q; j++) {
            assert(1 == fscanf(fr, "%d", &G[i][j]));
        }
    }

    fprintf(fw, "%d\n", compra(N, Q, G));
    fclose(fr);
    fclose(fw);
    return 0;
}
