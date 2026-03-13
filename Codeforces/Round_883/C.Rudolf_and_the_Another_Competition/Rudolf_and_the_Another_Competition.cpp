#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m, h; cin >> n >> m >> h;
        ll p1, pen1, pos = 1;
        for(int i = 0; i < n; ++i)
        {
            vector<ll> v(m);
            ll points = 0, penalties = 0, tmp = 0;
            for(int j = 0; j < m; ++j)
            {
                cin >> v[j];
            }
            sort(v.begin(), v.end());
            for(int j = 0; j < m; ++j)
            {
                if(tmp + v[j] <= h)
                {
                    tmp += v[j];
                    penalties += tmp;
                    points++;
                }
            }

            if(i == 0)
            {
                p1 = points;
                pen1 = penalties;
            } else if(points > p1 || (points == p1 && penalties < pen1)) pos++;
        }
        cout << pos << "\n";
    }
}