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

long long paletta_sort(int N, int V[])
{
    vector<int> v1; // pari
    vector<int> v2; // dispari
    for(int i = 0; i < N; ++i)
    {
        if(V[i] % 2 == 1 && i % 2 == 0)
        {
            return -1;
        }
        if(V[i] % 2 == 0 && i % 2 == 1)
        {
            return -1;
        }
        if(i % 2 == 0)
        {
            v1.push_back(V[i]);
        } else if(i % 2 == 1)
        {
            v2.push_back(V[i]);
        }
    }

    // bubblesort sui due vector
    long long ans = 0;
    //ans += bubblesort(v1);
    //ans += bubblesort(v2);

    ans += conta(v1);
    ans += conta(v2);

    return ans;
}

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
