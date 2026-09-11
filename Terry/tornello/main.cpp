#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int c; cin >> c;
        string prev;
        int ans = 0, mx = 0, mn = 0, cnt = 0;
        for(int j = 0; j < c; ++j)
        {
            string a; cin >> a;
            if(a == "-1")
            {
                cnt--;
            } else if(a == "+1")
            {
                cnt++;
            }
            if(cnt < mn)
            {
                ans++;
                mn = cnt;
            }
            if(cnt > mx)
            {
                ans++;
                mx = cnt;
            }
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
}