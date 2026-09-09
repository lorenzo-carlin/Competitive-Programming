#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int num;
    fin >> num;
    if(num % 2 == 0)
    {
        fout << "pari";
    } else
    {
        fout << "dispari";
    }
}
