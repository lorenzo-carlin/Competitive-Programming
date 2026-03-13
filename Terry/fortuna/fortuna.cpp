#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        int N; cin >> N;
        vector<int> sp(N);
        for(int i = 0; i < N; ++i)
        {
            cin >> sp[i];
        }
        vector<int> gioc(N);
        for(int i = 0; i < N; ++i)
        {
            cin >> gioc[i];
        }
        long long tot = LONG_MAX;
        for(int i = 0; i < N; ++i)
        {
            long long sum = 0;
            for(int j = 0; j < N; ++j)
            {
                sum += sp[j]*gioc[j];
            }
            if(sum < tot)
                tot = sum;
            int tmp = gioc.back();
            gioc.pop_back();
            gioc.insert(gioc.begin(), tmp);
        }
        cout << "Case #" << i << ": " << tot << endl;
    }
}