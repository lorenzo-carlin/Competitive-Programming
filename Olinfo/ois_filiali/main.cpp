#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, f;
vector<int> v;

bool possible(int val)
{
    int tmp = 0, cnt = 1;
    for(int i = 1; i < n; ++i)
    {
        tmp += v[i]-v[i-1];
        if(tmp >= val)
        {
            tmp = 0;
            cnt++;
        }
    }
    if(cnt >= f) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> f;
    v.resize(n);
    for(int &i: v) cin >> i;

    int l = 0, r = v.back();
    while(l < r-1)
    {
        int m = l + (r - l) / 2;
        if(possible(m)) l = m;
        else r = m;
    }
    if(possible(r)) cout << r << "\n";
    else cout << l << "\n";
}