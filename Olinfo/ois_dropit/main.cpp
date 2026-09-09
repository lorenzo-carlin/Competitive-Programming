#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    deque<int> d;
    
    int a;

    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        while(!d.empty() && a > d.back())
        {
            a -= d.back();
            d.pop_back();
        }
        if(d.empty())
        {
            d.push_back(a);
            continue;
        }
        if(a == d.back())
        {
            d.pop_back();
        } else if(a < d.back())
        {
            int tmp = d.back()-a;
            d.push_back(a);
            d.push_back(tmp);
        }
    }

    cout << d.size() << "\n";
    for(auto el: d)
    {
        cout << el << " ";
    }
    cout << "\n";
}