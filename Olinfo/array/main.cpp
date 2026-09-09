#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N, sum = 0;
    float med;
    fin >> N;
    int V[N];
    for(int i = 0; i < N; i++)
    {
        fin >> V[i];
        sum = sum + V[i];
    }
    med = (float) sum / N;
    fout << sum << " " << med;
    return 0;
}
