#include <bits/stdc++.h>
using namespace std;

bool check(string s, int dim)
{
    if(s.size() == 0)
    {
        return false;
    }
    int st = 0, fn = s.size()-dim;
    while(st < fn)
    {
        if(s.substr(st, dim) != s.substr(fn, dim))
        {
            return false;
        }
        st += dim;
        fn -= dim;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    for(int i = 1; i <= n; ++i)
    {
        if(n % i == 0)
        {
            if(check(s, i))
            {
                cout << i << "\n";
                break;
            }
        }
    }
}