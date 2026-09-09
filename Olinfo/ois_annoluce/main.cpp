#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int N, Q;
long double dist[MAX];
long double x, y, z;

int ricercaBinaria(long double x)
{
    int inizio = 0;
    int fine = N-1;
    if(dist[fine] <= x)
    {
        return fine;
    }
    while(fine-inizio > 1)
    {
        int mezzo = (inizio + fine + 1) / 2;
        if(dist[mezzo] > x)
        {
            fine = mezzo;
        } else
        {
            inizio = mezzo;
        }
    }
    return inizio;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> x >> y >> z;
        dist[i] = (long double)sqrt(x*x + y*y + z*z);
    }
    sort(dist, dist + N);
    cin >> Q;
    for(int i = 0; i < Q; ++i)
    {
        int x;
        cin >> x;
        int ans = ricercaBinaria(x) + 1;
        cout << ans << endl;
    }
    return 0;
}