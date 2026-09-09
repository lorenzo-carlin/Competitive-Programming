#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N, pos = 1, c = 0;
    fin >> N;
    char vec[N];
    for(int i = 0; i < N; i++)
    {
        fin >> vec[i];
        if(vec[i] == '_')
        {
            c++;
        }
    }
    int j = c;
    for(int i = 0; i < c; i++)
    {
        pos = pos * (26-(N-j));
        j--;
    }
    fout << pos;
    return 0;
}
