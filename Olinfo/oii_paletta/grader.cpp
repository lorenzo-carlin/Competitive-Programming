#include <bits/stdc++.h>
using namespace std;

static FILE *fr, *fw;

// Declaring variables
static int N;
static int* V;
static long long int numero_ribaltamenti;

// Declaring functions
long long bubblesort(vector<int> &v)
{
    long long cnt = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v.size()-(i+1); ++j)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                cnt++;
            }
        }
    }
    return cnt;
}

long long conta(vector<int> &v)
{
    long long ans = 0;
    for(int i = 0; i < v.size()-1; ++i)
    {
        for(int j = i+1; j < v.size(); ++j)
        {
            if(v[i] > v[j])
            {
                ans++;
            }
        }
    }
    return ans;
}

long long paletta_sort(int N, int V[]);

int main() {
	#ifdef EVAL
		fr = fopen("input.txt", "r");
		fw = fopen("output.txt", "w");
	#else
		fr = stdin;
		fw = stdout;
	#endif

	// Reading input
	fscanf(fr, "%d ", &N);
	V = (int*)malloc(N * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, "%d ", &V[i0]);
	}

	// Calling functions
	numero_ribaltamenti = paletta_sort(N, V);

	// Writing output
	fprintf(fw, "%lld\n", numero_ribaltamenti);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
