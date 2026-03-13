#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, o = 0;
    for(int i = 0; i < n; i++)
    {
        l += (s[i] == 'L');
        o += (s[i] == 'O');
    }

    int curl = 0, curo = 0;
    for(int i = 0; i < n-1; i++)
    {
        curl += (s[i] == 'L');
        curo += (s[i] == 'O');
        if(curl != (l - curl) && curo != (o - curo))
        {
            cout << i+1 << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
}
