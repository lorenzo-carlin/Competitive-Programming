#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    sort(v.begin(), v.end());

    for(int i = 0; i < n; ++i)
    {
        if(i < n-1 && (v[i] == v[i+1]-1 && v[i+1]-1 == v[i+2]-2))
        {
            int st = i;
            int tmp = 0;
            while(i < n && v[i] == v[i+1]-1)
            {
                tmp++;
                i++;
            }
            cout << v[st] << "-" << v[i] << " ";

        } else
        {
            cout << v[i] << " ";
        }

    }
}