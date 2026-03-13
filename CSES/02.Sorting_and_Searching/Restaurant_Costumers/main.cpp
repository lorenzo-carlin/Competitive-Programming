#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    deque<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int curr = 0, mx = 0;
    while(!a.empty())
    {
        if(a.front() < b.front())
        {
            curr++;
            mx = max(mx, curr);
            a.pop_front();
        } else if(a.front() > b.front())
        {
            curr--;
            b.pop_front();
        } else if(a.front() == b.front())
        {
            a.pop_front();
            b.pop_front();
        }
    }

    cout << mx << "\n";
}