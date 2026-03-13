#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
const int K = 3;

int main()
{
    int st[K+1][MAXN];

    for(int i = 0; i < K+1; ++i)
    {
        for(int j = 0; j < MAXN; ++j)
        {
            st[i][j] = -1;
        }
    }

    vector<int> array(10);
    for(int i = 0; i < 10; ++i)
    {
        cin >> array[i];
    }

    copy(array.begin(), array.end(), st[0]);

    /****************
    Range Sum Queries

    for(int i = 1; i <= K; i++)
    {
        for(int j = 0; j + (1 << i) <= 10; j++)
        {
            st[i][j] = st[i-1][j] + st[i-1][j + (1 << (i - 1))];
        }
    }

    int sum = 0, L, R;
    cin >> L >> R;
    for(int i = K; i >= 0; i--)
    {
        if((1 << i) <= R - L + 1)
        {
            sum += st[i][L];
            L += 1 << i;
        }
    }

    cout << sum << "\n";
    */
    
    
    //Range Minimum Queries (RMQ)

    int lg[MAXN+1];
    lg[1] = 0;
    for(int i = 2; i <= MAXN; ++i)
    {
        lg[i] = lg[i/2]+1;
    }

    for(int i = 1; i <= K; ++i)
    {
        for(int j = 0; j + (1 << i) <= 10; ++j)
        {
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << i - 1)]);
        }
    }

    int i, L, R; cin >> L >> R;
    i = lg[R - L + 1];
    int mn = min(st[i][L], st[i][R - (1 << i) + 1]);

    for(int i = 0; i < K+1; ++i)
    {
        for(int j = 0; j < MAXN; ++j)
        {
            cout << st[i][j] << " ";
        }
        cout << "\n";
    }

    cout << mn << "\n";
    
}