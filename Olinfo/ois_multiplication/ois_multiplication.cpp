#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> dig;
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int m; cin >> m;
        int j = 1;
        while(true)
        {
            int tmp = m*j;
            while(tmp > 0)
            {
                int d = tmp % 10;
                dig.insert(d);
                tmp = tmp / 10;
            }
            if(dig.size() == 10)
            {
                cout << j << endl;
                dig.clear();
                break;
            }
            j++;
        }
    }
}