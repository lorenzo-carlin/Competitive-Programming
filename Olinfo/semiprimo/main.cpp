#include <bits/stdc++.h>
using namespace std;

bool primo(int n)
{
    for(int i = 2; i*i <= n; ++i) if(n % i == 0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    for(int i = 2; i*i <= n; ++i)
    {
        if(n % i == 0)
        {
            if(primo(i) && primo(n/i))
            {
                cout << i << " " << n/i << "\n";
            } else
            {
                cout << -1 << "\n";
            }
            break;
        }
    }
}