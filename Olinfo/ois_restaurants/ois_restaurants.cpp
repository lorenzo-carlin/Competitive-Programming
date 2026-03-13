#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    int mx = -1, mx_ind = -1;
    for(int i = 1; i <= n; ++i)
    {
        int curr = 0;
        for(int j = 1; j <= n+1; ++j)
        {
            int a; cin >> a;
            curr += a;
        }
        if(curr > mx)
        {
            mx = curr;
            mx_ind = i;
        }
        cout << mx_ind << "\n";
    }
}