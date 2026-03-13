#include <bits/stdc++.h>
using namespace std;

long long compute(long long n)
{
    long long sum = 0;
    for(long long i = 1; i <= n/2; ++i)
    {
        sum += (n/i);
    }
    sum += n - (n/2);
    return sum;
}

// long long compute(long long n)
// {
//     long long sum = 0;
//     int rad = sqrt(n);
//     for(int i = 1; i <= rad; ++i)
//     {
//         int div = n/i, div1 = n/(i+1);
//         if(div == i)
//             sum += div;
//         else
//             sum += (div)+((div-div1)*i);
//     }
//     return sum;
// }

int main()
{
    long long n; cin >> n;
    long long ans = compute(n);
    cout << ans;
}