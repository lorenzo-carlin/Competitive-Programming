#include <bits/stdc++.h>
using namespace std;

const int N = 3;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int T;
    fin >> T;
    for(int i = 0; i < T; i++)
    {
        int a1, a2, b1, b2, c1, c2;
        fin >> a1;
        fin >> a2;
        fin >> b1;
        fin >> b2;
        fin >> c1;
        fin >> c2;
        int i1, i2, t1, t2;
        if(a1 <= b1 && a2 >= b2)
        {
            i1 = b1;
            i2 = b2;
        } else if(a1 >= b1 && a2 <= b2)
        {
            i1 = a1;
            i2 = a2;
        } else if(a1 <= b1 && a2 <= b2)
        {
            i1 = b1;
            i2 = a2;
        } else if(b1 <= a1 && b2 <= a2)
        {
            i1 = a1;
            i2 = b2;
        }
        if(i1 <= c1 && i2 >= c2)
        {
            t1 = c1;
            t2 = c2;
        } else if(i1 >= c1 && i2 <= c2)
        {
            t1 = i1;
            t2 = i2;
        } else if(i1 <= c1 && i2 <= c2)
        {
            t1 = c1;
            t2 = i2;
        } else if(c1 <= i1 && c2 <= i2)
        {
            t1 = i1;
            t2 = c2;
        }
        int ris = t2 - t1;
        fout << "Case #" << i + 1 << ": " << ris << endl;
    }
    return 0;

}