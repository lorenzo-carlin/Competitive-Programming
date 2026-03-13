#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> s;

    while(n > 0)
    {
        int r = n % 2;
        if(r == 1)
        {
            s.push_back(1);
        } else
        {
            s.push_back(0);
        }
        n = n/2;
    }
    
    reverse(s.begin(), s.end());
    
    int x = 1, cnt = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        cnt += (s[i]*x);
        x = x*2;
    }

    cout << cnt;
}