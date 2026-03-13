#include <iostream>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int a, b, c; cin >> a >> b >> c;
    int tm1 = (a+b+c);
    
    int mx = 0;
    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b >> c;
        if(a+b+c > mx)
        {
            mx = a+b+c;
        }
    }
    
    int ans = (mx+m*100)-tm1+1;
    if(ans < 0)
    {
        ans = 0;
    }
    cout << ans << "\n";
}