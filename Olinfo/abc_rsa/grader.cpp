#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void decifra(int N, int d, int L, int messaggio[], char plaintext[]);

int main()
{
    int N, d, L;
    cin >> N >> d >> L;
    int messaggio[L];
    for(int i = 0; i < L; ++i)
    {
        cin >> messaggio[i];
    }
    char plaintext[L];
    decifra(N, d, L, &messaggio[0], &plaintext[0]);
    for(int i = 0; i < L; ++i)
    {
        cout << plaintext[i];
    }
    return 0;
}