/*
 * Binary Search
 * Searches for a target value in a sorted sequence by repeatedly halving
 * the search interval in O(log n) time.
 */


#include <bits/stdc++.h>
using namespace std;

// Recursive
int binary_search(int l, int r, vector<int> &v, int x)
{
    if(l > r) return -1;
    int m = (l + r) / 2;
    if(v[m] == x) return m;
    if(v[m] > x) return binary_search(l, m-1, v, x);
    return binary_search(m+1, r, v, x);
}

int main()
{
    int n; cin >> n;

    vector<int> v(n);
    for(auto &i: v) cin >> i;

    sort(v.begin(), v.end());

    int x; cin >> x;
    cout << binary_search(0, n-1, v, x) << "\n";

    // Iterative
    int l = 0, r = n-1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(v[m] == x)
        {
            cout << m << "\n";
            break;
        } else if(v[m] > x)
        {
            r = m-1;
        } else
        {
            l = m+1;
        }
    }
    if(l > r) cout << -1 << "\n";

}
