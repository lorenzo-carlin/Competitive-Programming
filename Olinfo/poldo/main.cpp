#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n; cin >> n;
    int array[n], length[n];
    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> array[i];
        length[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(array[j] > array[i])
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