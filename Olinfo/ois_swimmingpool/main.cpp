#include <iostream>
#include <fstream>
using namespace std;
#define MAXN 100000

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin >> N;
    int P[MAXN];
    for(int i = 0; i < N; i++)
    {
        fin >> P[i];
    }
    int mn = 1000000;
    for(int j = 1; j < N - 1; j++)
    {
        int sx = P[j] - P[0];
        int dx = P[N-1] - P[j];
        if(max(sx, dx) < mn)
        {
            mn = max(sx, dx);
        }
    }
    if(N == 2)
    {
        mn = P[N-1] - P[0];
    }
    fout << mn;
    return 0;
}
