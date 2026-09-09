#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    ll cnt = 0;

    int dim_x; cin >> dim_x;
    vector<pair<int,int>> x(dim_x);
    for(auto &i: x) cin >> i.first >> i.second;
    int dim_y; cin >> dim_y;
    vector<pair<int,int>> y(dim_y);
    for(auto &i: y) cin >> i.first >> i.second;

    int i = 0, j = 0;
    int a, b, c, d;
    while(i != dim_x && j != dim_y)
    {
        a = x[i].first;
        b = x[i].second;
        c = y[j].first;
        d = y[j].second;

        if(a == c || b == d)                        // caso 0
        {
            if(a == c && b == d)
            {
                cnt += (d-a+1);
                i++;
                j++;
            } else if(a == c)
            {
                if(b > d)
                {
                    cnt += (d-a+1);
                    x[i].first = d+1;
                    j++;
                } else
                {
                    cnt += (b-a+1);
                    i++;
                }
            } else
            {
                if(a < c)
                {
                    if((c-a) < t)
                    {
                        cnt += (d-c+1);
                        j++;
                    }
                    i++;
                } else
                {
                    cnt += (b-a+1);
                    i++;
                    j++;
                }
            }
        } else if(a < c && b > d)                 // caso 1
        {
            if((c-a) >= t)
            {
                i++;
            } else
            {
                cnt += (d-c+1);
                x[i].first = d+1;
            }
            j++;
        } else if(a > c && b < d)                 // caso 2
        {
            cnt += (b-a+1);
            y[j].first = b+1;
            i++;
        } else if(b < c)                          // caso 3
        {
            i++;
        } else if(a > d)                          // caso 4
        {
            j++;
        } else if(b >= c && a <= c && b <= d)     // caso 5
        {
            if((c-a) < t)
            {
                cnt += (b-c+1);
            }
            i++;
        } else if(a >= c && a <= d && b >= d)     // caso 6
        {
            cnt += (d-a+1);
            x[i].first = d+1;
            j++;
        }
    }

    cout << cnt;
}