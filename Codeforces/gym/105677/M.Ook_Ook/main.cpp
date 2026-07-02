#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string o = ".-.-";
    string k = ".-";

    string s; cin >> s;
    int n = s.size();
    int idx = 0;
    while(idx < n)
    {
        if(s[idx] == 'O') cout << o;
        else cout << k;
        idx++;
    }
    cout << "\n";
}
