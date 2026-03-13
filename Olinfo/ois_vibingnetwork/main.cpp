#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, t, k; cin >> n >> t >> k;
    vector<int> v(t);
    for(int &i: v) cin >> i;

    int streak = 0;
    for(int i = 0; i < t; i++)
    {
        if(v[i]*100 >= 67*n)
            streak++;
        else
            streak = 0;

        if(streak == k)
        {
            cout << i-k+2 << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
}
