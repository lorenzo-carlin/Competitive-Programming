#include <stdio.h>
#include <assert.h>
#define MAXN 1000000

static FILE *fr, *fw;

static int N;
static int C[MAXN];

void Diversifica(int, int[]);

void Vernicia(int i, int c) {
    fprintf(fw, "%d %d\n", i, c);
}

int main() {
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));

    int i;
    for (i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &(C[i])));

    Diversifica(N, C);

    fclose(fr);
    fclose(fw);
    return 0;
}
