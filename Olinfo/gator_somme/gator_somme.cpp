#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    priority_queue<int> min_prq;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        min_prq.push(-a);
    }

    ll ans = 0;
    while(min_prq.size() > 1)
    {
        int a = -min_prq.top();
        min_prq.pop();
        int b = -min_prq.top();
        min_prq.pop();
        ans += (a + b);
        min_prq.push(-(a+b));
    }

    cout << ans << "\n";
}