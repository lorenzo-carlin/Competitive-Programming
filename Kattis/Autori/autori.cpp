#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[100];
    cin >> s;
    int l = strlen(s);
    for(int i = 0; i < l; i++)
    {
        char c = s[i];
        if(c >= 'A' && c <= 'Z')
        {
            cout << c;
        }
    }
    return 0;
}
