#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, d; cin >> n >> d;
    vector<int> v(n);
    int sum = 0;
    for(auto &i: v)
    {
        cin >> i;
        sum += i;
    }
    sort(v.begin(), v.end());
    int m; cin >> m;
    int tot = 0;
    if(m < n)
    {
        for(int i = 0; i < m; ++i)
        {
            tot += v[i];
        }
    } else
    {
        tot = sum;
        tot -= (m-n)*d;
    }
    cout << tot << "\n";
}