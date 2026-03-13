#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N, sommamx = -1;
    fin >> N;
    for(int i = 0; i < N; i++)
    {
        int a, b, somma;
        fin >> a;
        fin >> b;
        somma = a + b;
        if(somma % 2 == 0)
            if(somma > sommamx)
                sommamx = somma;
    }
    fout << sommamx;
    return 0;
}
