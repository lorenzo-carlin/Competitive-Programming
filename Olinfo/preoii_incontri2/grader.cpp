#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static FILE *in, *out;
static int N, *A, i;

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

int main() {
  in = stdin;
  out = stdout;

  assert(fscanf(in, "%d", &N) == 1);
  A = (int*)malloc(N * sizeof(int));
  for (i = 0; i < N; i++) {
    assert(fscanf(in, "%d", A + i) == 1);
  }

  if (visita(N, A)) {
    fprintf(out, "Emil\n");
  } else {
    fprintf(out, "Gemma\n");
  }

  return 0;
}
