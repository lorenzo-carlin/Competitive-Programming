#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;

    unordered_set<int> s;

    queue<pair<int,int>> q;
    q.push({n, 0});
    s.insert(n);
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // caso base
        if(x == 0)
        {
            cout << y << "\n";
            break;
        }

        // aggiunge 1
        if(x+1 <= 1e9 && s.count(x+1)==0)
        {
            q.push({x+1, y+1});
            s.insert(x+1);
        }

        // toglie 1
        if(s.count(x-1)==0)
        {
            q.push({x-1, y+1});
            s.insert(x-1);
        }

        // moltiplica per 2
        if(2*x <= 1e9 && s.count(2*x)==0)
        {
            q.push({2*x, y+1});
            s.insert(2*x);
        }

        // divide per una potenza di 3
        int pow = 3;
        while(pow <= x)
        {
            if(x % pow == 0 && s.count(x/pow)==0)
            {
                q.push({x/pow, y+1});
                s.insert(x/pow);
            }
            pow *= 3;
        }
    }
}