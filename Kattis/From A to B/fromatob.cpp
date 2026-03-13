#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int A, B;
    cin >> A;
    cin >> B;
    int n = 0;
    while(A != B)
    {
        if(A < B)
        {
            n = n + (B - A);
            A = B;
        } else if(A % 2 != 0)
        {
            A++;
            n++;
        } else
        {
            A = A / 2;
            n++;
        }
    }
    cout << n;
    return 0;
}
