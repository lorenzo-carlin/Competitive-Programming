#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s;
    for(int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        s += c;
    }

    for(int i = 1; i <= n/2; ++i)
    {
        if(n % i) continue;

        string cur = s.substr(0, i);
        bool cond = true;
        for(int j = i; j + i <= n; j += i)
        {
            string tmp = s.substr(j, i);
            if(cur != tmp)
            {
                cond = false;
                break;
            }
        }
        if(cond)
        {
            for(char el: cur) cout << el << " ";
            cout << "\n";
            return 0;
        }
    }

    cout << 2 << "\n";
}