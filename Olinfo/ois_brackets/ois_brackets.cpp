#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int n, k; cin >> n >> k;
    stack<int> st;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        if(!st.empty() && a == st.top())
        {
            st.pop();
        } else
        {
            st.push(a);
        }
    }
    if(st.empty()) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--)
    {
        cout << solve() << "\n";
    }
}