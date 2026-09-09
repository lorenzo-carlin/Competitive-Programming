#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    priority_queue<int> pos;
    priority_queue<int> neg;
    int s_pos = 0;
    int s_neg = 0;
    for(int i = 0; i < n; ++i)
    {
        int num; cin >> num;
        if(num > 0)
        {
            pos.push(num);
            s_pos += num;
        } else
        {
            neg.push(abs(num));
            s_neg += abs(num);
        }
    }
    int ans = 0;
    while(s_neg >= s_pos)
    {
        int tmp = neg.top();
        pos.push(tmp);
        s_pos += tmp;
        neg.pop();
        s_neg -= tmp;
        ans++;
    }
    cout << ans;
    return 0;
}