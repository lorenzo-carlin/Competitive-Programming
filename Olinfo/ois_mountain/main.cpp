#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] == n-1)
        {
            k = i;
        }
    }

    int last = v[0];
    int cnt = 0;
    for(int i = 1; i < k; i++)
    {
        if(v[i] < last)
        {
            cnt++;
        } else
        {
            last = v[i];
        }
    }
    last = v[n-1];
    for(int i = n-2; i > k; i--)
    {
        if(v[i] < last)
        {
            cnt++;
        } else
        {
            last = v[i];
        }
    }

    cout << cnt << "\n";
}
