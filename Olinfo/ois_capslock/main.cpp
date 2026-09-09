#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    cin.ignore();
    string s; getline(cin, s);
    for(int i = 0; i < n; ++i)
    {
        if(isalpha(s[i]))
        {
            if(isupper(s[i])) s[i] = tolower(s[i]);
            else s[i] = toupper(s[i]);
        }
    }
    cout << s << "\n";
}