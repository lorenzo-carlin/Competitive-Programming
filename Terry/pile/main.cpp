#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int T;
    fin >> T;
    for(int i = 1; i <= T; i++)
    {
        int N;
        fin >> N;
        int sum = 0;
        for(int j = 0; j < N; j++)
        {
            int a, b, c, mx;
            fin >> a;
            fin >> b;
            fin >> c;
            if(a >= b && a >= c)
            {
                mx = a;
            } else if(b >= a && b >= c)
            {
                mx = b;
            } else if(c >= a && c >= b)
            {
                mx = c;
            }
            sum += mx;
        }
        fout << "Case #" << i << ": " << sum << endl;
    }
    return 0;
}