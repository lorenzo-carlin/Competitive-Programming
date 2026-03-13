#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void Accendi(int n, int acceso[], int pulsante[])
{
    for(int i = n; i > 0; i--)
    {
        int cnt = 0;
        for(int j = i; j <= n; j += i)
            cnt += pulsante[j];
        pulsante[i] = ((cnt%2) != !acceso[i]);
    }
}
