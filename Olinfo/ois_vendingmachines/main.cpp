#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int N, Q;
        cin >> N >> Q;
        int p[N], t[Q];
        for(int i = 0; i < N; ++i)
        {
            cin >> p[i];
        }
        int m = 0;
        for(int i = 0; i < Q; ++i)
        {
            cin >> t[i];
        }
        for(int i = 0; i < Q; ++i)
        {
            if(t[i] > 0)
            {
                m += t[i];
            } else
            {
                int temp = abs(t[i]);
                m -= p[temp-1];
            }
            if(m < 0)
            {
                cout << "HACKER" << endl;
                break;
            }
            if(i == Q-1)
            {
                cout << "OK" << endl;
            }
        }
    }
    return 0;
}