#include <bits/stdc++.h>
using namespace std;

int c(int num)
{
    int sol = 0;
    while(num != 1)
    {
        if(num % 2) num = num * 3 + 1;
        else num = num / 2;
        sol++;
    }
    return sol;
}

int p(int num, int mx)
{
    int sol = 0;
    while(num != 1 && sol < mx)
    {
        if(num % 2) num = num * 5 + 1;
        else num = num / 2;
        sol++;
    }
    return sol;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b; cin >> a >> b;
    int tot = 0;
    for(; a <= b; a++)
    {
        int col = c(a);
        int pol = p(a, col);
        if(pol < col) tot++;
    }

    cout << tot << "\n";
}