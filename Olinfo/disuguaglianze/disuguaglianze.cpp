#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> num(n);
    for(int i = 1; i <= n; ++i)
    {
        num[i-1] = i;
    }
    for(int i = 0; i < n-1; ++i)
    {
        char c; cin >> c;
        if(c == '<')
        {
            cout << num.front() << " ";
            num.erase(num.begin());
        } else if(c == '>')
        {
            cout << num.back() << " ";
            num.pop_back();
        }
    }
    cout << num[0];
    return 0;
}