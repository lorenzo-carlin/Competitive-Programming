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
        int ans = 0;
        for(int j = 0; j < N; ++j)
        {
            int A; cin >> A;
            if(A > 0)
            {
                ans += A;
            }
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}