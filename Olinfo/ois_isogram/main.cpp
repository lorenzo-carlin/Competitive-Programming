#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    int count = 0;
    string bin; getline(cin, bin);
    for(int i = 0; i < N; ++i)
    {
        bool cond = true;
        string s;
        getline(cin, s);
        char c1 = 'A';
        char c2 = 'a';
        for(int x = 0; x < 26; ++x)
        {
            int p = 0;
            for(int j = 0; j < s.size(); ++j)
            {
                if(s[j] == c1 || s[j] == c2)
                    p++;
                if(p > 2)
                    cond = false;
            }
            c1++;
            c2++;
        }
        if(cond)
            count++;
    }
    cout << count;
}