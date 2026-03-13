#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    string fr;
    for(int i = 0; i < (s.size()-1); ++i)
    {
        if(s[i] < s[i+1])
        {
            fr += s.substr(i+1, s.size()-i+1);
            break;
        } else
        {
            fr += s[i];
        }
    }
    return fr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string f, tmp = s;
    for(int i = 0; i < k; ++i)
    {
        f = solve(tmp);
        tmp = f;
    }
    cout << f << endl;
}