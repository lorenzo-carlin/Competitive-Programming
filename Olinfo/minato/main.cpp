#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    cin >> N >> M;
    int cnt[N+1][M+1];
    for(int i = 0; i < N+1; ++i)
    {
        for(int j = 0; j < M+1; ++j)
        {
            cnt[i][j] = 0;
        }
    }
    cnt[1][1] = 1;
    char c;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            cin >> c;
            if(c == '*')
            {
                cnt[i][j] += cnt[i-1][j] + cnt[i][j-1];
            }
        }
    }
    cout << cnt[N][M];
    return 0;
}