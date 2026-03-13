#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mx = 0, wn = -1;
    for(int i = 0; i < 5; ++i)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int sum = a + b + c + d;
        if(sum > mx)
        {
            mx = sum;
            wn = i+1;
        }
    }
    cout << wn << " " << mx << "\n";
}