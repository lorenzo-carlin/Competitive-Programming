#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> p(n);
    vector<int> c(n);

    for(auto &i:p) cin >> i;

    int mx = 0;
    int cnt = 0;

    cin >> c[0];

    for(int i = 0; i < n-1; ++i)
    {
        cin >> c[i+1];
        if(c[i] == 1)
        {
            if(c[i] == 1 && c[i+1] == 1)
            {
                if(p[i] <= p[i+1])
                {
                    cnt += p[i];
                } else
                {
                    cnt += p[i];
                    mx = max(mx, cnt);
                    cnt = 0;
                }
            } else if(c[i] == 1 && c[i+1] == 0)
            {
                cnt += p[i];
                mx = max(mx, cnt);
                cnt = 0;
            }
        }
    }
    if(c[n-1] == 1 && c[n-2] == 1 && p[n-1] >= p[n-2])
    {
        cnt += p[n-1];
        mx = max(mx, cnt);
    }
    
    cout << mx;
}