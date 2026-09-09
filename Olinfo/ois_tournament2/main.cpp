#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int K; cin >> K;
    for(int i = 0; i < K; ++i)
    {
        int N; cin >> N;
        int R; cin >> R;
        int T; cin >> T;
        int sum = 0;
        for(int i = 0; i < N; ++i)
        {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
        int med = sum / N;
        if(med >= (R + T))
        {
            cout << "Cheater" << endl;
        } else
        {
            cout << "Innocent" << endl;
        }
    }
    return 0;
}