#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        char c = s[0];
        int p = s[1] - '0';

        // stampo la riga
        for(char tmp = 'a'; tmp < 'i'; tmp++)
        {
            if(tmp != c) cout << tmp << p << "\n";
        }

        // stampo la colonna
        for(int i = 1; i < 9; ++i)
        {
            if(i != p) cout << c << i << "\n";
        }
    }
}
