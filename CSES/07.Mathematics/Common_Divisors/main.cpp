#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e6+5;

int main()
{
    vector<int> cnt(MAXN+1, 0);
    
    int n; cin >> n;
    for(int i = 0, a; i < n; ++i)
    {
        cin >> a;
        cnt[a]++;
    }

    for(int i = MAXN; i >= 0; i--)
    {
        int div = 0;
        for(int j = i; j <= MAXN; j += i)
        {
            div += (cnt[j]);
        }
        if(div >= 2)
        {
            cout << i << "\n";
            break;
        }
    }
}
