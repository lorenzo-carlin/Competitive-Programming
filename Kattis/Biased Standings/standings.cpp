#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t; cin >> t;
    for(int x = 0; x < t; ++x)
    {
        vector<int> v;
        int N; cin >> N;
        for(int i = 0; i < N; ++i)
        {
            string s; cin >> s;
            int pos; cin >> pos;
            v.push_back(pos);
        }
        ll ans = 0;
        sort(v.begin(), v.end());
        for(int i = 1; i <= N; ++i)
        {
            int tmp = v[i-1];
            ans += (abs(tmp-i));
        }
        cout << ans << endl;
    }
}