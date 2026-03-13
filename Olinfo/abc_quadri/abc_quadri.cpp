#include <bits/stdc++.h>
using namespace std;

int quadri(int N, long long M, int V[])
{
    int count = 0;
    long sum = 0; // or int sum = 0; (?)
    for(int i = 0; i < N; ++i)
    {
        sum += V[i];
        if(sum > M)
        {
            break;
        } else
        {
            count++;
        }
    }
    if(count == N)
    {
        return count;
    }
    for(int i = 1; i < N; ++i)
    {
        sum = 0;
        int j = 0;
        int c = 0;
        while(i + j < N)
        {
            sum += V[i+j];
            if(sum > M)
            {
                break;
            } else
            {
                c++;
                j++;
            }
        }
        count = min(count, c);
        if(i + j >= N)
        {
            break;
        }
    }
    return count;
}

int main()
{
    int N;
    long long M;
    cin >> N >> M;
    int V[N];
    for(int i = 0; i < N; ++i)
    {
        cin >> V[i];
    }
    int ans = quadri(N, M, V);
    cout << ans;
    return 0;
}