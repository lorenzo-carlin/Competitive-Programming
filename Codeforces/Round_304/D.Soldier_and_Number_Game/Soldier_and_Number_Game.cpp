#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5*1e6+5;
ll v[MAXN], fre[MAXN];

void prec()
{
    iota(v, v+MAXN, 0);
    for(int i = 2; i*i <= MAXN; ++i)
        if(v[i] == i)
            for(int j = i*i; j <= MAXN; j += i)
                if(v[j] == j) v[j] = i;
    for(int i = 1; i < MAXN; ++i)
    {
        int tmp = i, cnt = 0;
        while(tmp != 1)
        {
            tmp /= v[tmp];
            cnt++;
        }
        fre[i] = cnt;
    }
    for(int i = 2; i < MAXN; ++i) fre[i] += fre[i-1];
}

void solve()
{
    int a, b; cin >> a >> b;
    cout << fre[a] - fre[b] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prec();

    int t; cin >> t;
    while(t--) solve();
}
