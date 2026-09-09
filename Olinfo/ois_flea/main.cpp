#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        if(c == 'R')
            cnt++;
        if(c == 'L')
            cnt--;
    }
    cout << abs(cnt);
}