#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;

    vector<ll> st(n), fn(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> st[i] >> fn[i];
    }

    sort(st.rbegin(), st.rend());
    sort(fn.rbegin(), fn.rend());

    ll curr = 0, tot = 0;
    while(!st.empty())
    {
        if(st.back() < fn.back())
        {
            tot += (curr+1);
            curr++;
            st.pop_back();
        } else
        {
            tot += curr;
            curr--;
            fn.pop_back();
        }
    }
    tot += (curr+1)*curr/2;
    cout << tot << "\n";
}