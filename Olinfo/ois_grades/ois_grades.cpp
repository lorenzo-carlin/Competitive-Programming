#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    int ins = -1, suf = -1;
    for(int i = 0; i < n; ++i)
    {
        if(v[i] < 6)
        {
            ins = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; --i)
    {
        if(v[i] >= 6)
        {
            suf = i;
            break;
        }
    }
    if(ins == -1 or suf == -1 or suf < ins)
    {
        cout << "-1\n";
    } else
    {
        cout << suf-ins+1 << "\n";
    }
    return 0;
}