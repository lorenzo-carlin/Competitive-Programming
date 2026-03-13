#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string mes;
        cin >> mes;
        int l = sqrt(size(mes));
        char m[l][l];
        int k = 0;
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < l; j++)
            {
                m[i][j] = mes[k];
                k++;
            }
        }
        string coded;
        for(int j = l - 1; j >= 0; j--)
        {
            for(int i = 0; i < l; i++)
            {
                cout << m[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}