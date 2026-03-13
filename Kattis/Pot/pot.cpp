#include <bits/stdc++.h>
using namespace std;

int fast_pow(int base, int exp)
{
    if(exp == 0)
    {
        return 1;
    }
    if(exp == 1)
    {
        return base;
    }
    int f = fast_pow(base, exp/2);
    f = f * f;
    if(exp % 2 == 1)
    {
        f = f * base;
    }
    return f;
}

int main()
{
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int num; cin >> num;
        int exp = num % 10;
        num = num / 10;
        sum += fast_pow(num, exp);
    }
    cout << sum;
    return 0;
}