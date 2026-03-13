#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int sum = 0;
    int cnt = 0;
    while(n--)
    {
        int a; cin >> a;
        if(a != -1)
        {
            sum += a;
            cnt++;
        }
    }
    float ans = (float)sum/cnt;
    cout << ans;
}