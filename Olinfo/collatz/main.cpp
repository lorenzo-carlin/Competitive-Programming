#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N, c = 1;
    fin >> N;
    while(N != 1)
    {
        if(N % 2 == 0)
        {
            N = N / 2;
            c++;
        } else
        {
            N = N * 3 + 1;
            c++;
        }
    }
    fout << c;
}
