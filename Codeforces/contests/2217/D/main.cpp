#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &i: v) cin >> i;
    set<int> s;
    int set;
    for(int i = 0, c; i < k; i++)
    {
        cin >> c;
        s.insert(c);
        set = v[c-1];
    }

    vector<int> b(n+2);
    b[0] = b[n+1] = 1;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == set)
        {
            b[i+1] = 1;
        } else
        {
            b[i+1] = 0;
        }
    }

    vector<int> blocks(k+1, 0);
    int idx = 0;
    for(int i = 0; i < n+1; i++)
    {
        if(s.count(i))
        {
            idx++;
        }
        if(b[i] != b[i+1])
        {
            blocks[idx]++;
        }
    }

    int sum = 0, mxx = 0;
    for(int i = 0; i < k+1; i++)
    {
        sum += blocks[i];
        mxx = max(mxx, blocks[i]);
    }

    if(mxx <= sum/2)
    {
        cout << (sum+1)/2 << "\n";
    } else
    {
        cout << mxx << "\n";
    }
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
