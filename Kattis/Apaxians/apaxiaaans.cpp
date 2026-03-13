#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[250];
    cin >> s;
    cout << s[0];
    for(int i = 1; i < strlen(s); i++)
    {
        if(s[i] != s[i - 1])
            cout << s[i];
    }
    return 0;
}