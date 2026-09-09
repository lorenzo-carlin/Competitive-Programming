#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, l; cin >> n >> e >> l;
    vector<int> v(n, l);

    int lb = 0;
    for(int i = 0; i < e; ++i)
    {
        int a; char b; cin >> a >> b;
        if(b == 'e')
        {
            lb++;
            v[a]++;
        } else
        {
            int c; cin >> c;
            v[c]--;
        }
    }

    int sol = 0;
    for(int i = 0; i < n; ++i)
    {
        if(v[i] > lb) sol++;
    }
    
    cout << sol << "\n";
}