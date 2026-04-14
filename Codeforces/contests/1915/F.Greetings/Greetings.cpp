#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// per usare l'ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i) // O(n)
        cin >> v[i].second >> v[i].first;

    sort(begin(v), end(v)); // O(nlogn)

    ll sol = 0;
    ordered_set st;

    for(int i = 0; i < n; ++i) // O(nlogn)
    {
        sol += st.size() - st.order_of_key(v[i].second);

        st.insert(v[i].second);
    }

    cout << sol << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
