#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    cin >> M;
    int dif;
    dif = fabs(N - M) + 1;
    int vec[dif];
    int mn = min(N, M) + 1;
    for(int i = 0; i < dif; i++)
    {
        vec[i] = mn;
        cout << vec[i] << endl;
        mn++;
    }
    return 0;
}
