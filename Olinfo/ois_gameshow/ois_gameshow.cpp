#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> p(n);
    vector<int> c(n);
    for(auto &i: p) cin >> i;
    for(auto &i: c) cin >> i;
    int t = 0;
    for(int i = 0; i < n; ++i)
    {
        if(p[i] <= m)
        {
            t++;
            m -= p[i];
        } else
        {
            m += c[i];
        }
    }
    cout << t << " " << m;
    return 0;
}