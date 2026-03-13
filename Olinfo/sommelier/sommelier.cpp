#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n; cin >> n;
    int array[n];
    int length[n];
    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> array[i];
        length[i] = 1;
        for(int j = 0; j < i-1; ++j)
        {
            if(array[i] >= array[j])
            {
                length[i] = max(length[i], length[j]+1);
            }
        }
        if(length[i] > mx)
        {
            mx = length[i];
        }
    }
    return mx;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ris = solve();
    cout << ris;
    return 0;
}