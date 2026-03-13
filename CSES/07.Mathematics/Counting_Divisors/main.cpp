#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    while(n--)
    {
        int a; cin >> a;
        int tot = 0;
        int i = 1;
        for(; i*i < a; ++i)
        {
            if(a%i == 0) tot++;
        }
        tot *= 2;
        if(i*i == a) tot++;
        cout << tot << "\n";
    }
}