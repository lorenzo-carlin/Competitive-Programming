#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int T;
    fin >> T;
    for(int i = 0; i < T; i++)
    {
        long long int A, B;
        fin >> A;
        fin >> B;
        if(A <= 0 && B >=0)
            fout << "0" << endl;
        else if(A > 0 && B > 0)
            fout << "+" << endl;
        else if((B - A) % 2 == 0)
            fout << "-" << endl;
        else if((B - A) % 2 != 0)
            fout << "+" << endl;
    }
    return 0;
}
