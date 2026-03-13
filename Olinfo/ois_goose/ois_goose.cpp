#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> v(n);
    for(auto &i: v) cin >> i;

    for(int i = 1; i <= 6; ++i)
    {
        int pos = 0, roll = 0;
        while(pos < n)
        {
            roll++;
            pos += i;
            while(pos < n && v[pos] != 0)
            {
                pos += v[pos];
            }
        }
        cout << roll << " ";
    }
}