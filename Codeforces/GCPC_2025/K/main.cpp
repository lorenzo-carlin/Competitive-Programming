#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, a, b; cin >> n >> a >> b;
    if(a+b-1 > n || a+b <= 2)
    {
        cout << "no\n";
        return 0;
    }

    vector<int> ans(n, -1);

    if(a == 1)
    {
        ans[0] = n;
        for(int i = n-b+1, j = 0; i < n; i++, j++)
        {
            ans[i] = n-1-j;
        }
    } else if(b == 1)
    {
        ans[n-1] = n;
        for(int i = a-2, j = 0; i >= 0; i--, j++)
        {
            ans[i] = n-1-j;
        }
    } else
    {
        for(int i = 0; i < a; i++)
        {
            ans[i] = n-a+i+1;
        }

        for(int i = n-b+1, j = 0; i < n; i++, j++)
        {
            ans[i] = n-a-j;
        }
    }

    for(int i = 0, j = 1; i < n; i++)
    {
        if(ans[i] == -1)
        {
            ans[i] = j;
            j++;
        }
    }

    cout << "yes\n";
    for(int el: ans) cout << el << " ";
    cout << "\n";
}
