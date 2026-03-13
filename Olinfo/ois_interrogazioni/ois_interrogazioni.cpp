#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, K; cin >> N >> K;
    int voti[N];
    for(int i = 0; i < N; ++i)
    {
        cin >> voti[i];
    }
    sort(voti, voti + N);
    int ans = INT_MAX;
    for(int i = 0; i < (N-K+1); ++i)
    {
        int tmp = voti[i+K-1] - voti[i];
        if(tmp < ans)
            ans = tmp;
    }
    cout << ans;
    return 0;
}