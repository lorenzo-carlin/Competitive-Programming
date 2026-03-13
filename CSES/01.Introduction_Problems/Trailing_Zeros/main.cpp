#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int cont = 0, t = 5;
    while(t <= n)
    {
        cont += n/t;
        t *= 5;
    }
    cout << cont << "\n";
}