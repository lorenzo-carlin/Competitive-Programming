/*
 * Longest Increasing Subsequence
 * Finds the longest subsequence of a sequence whose elements are in strictly
 * increasing order.
 */


#include <bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int n, int m)
{
    int mx = -1;
    if(n == 0 || m == 0) mx = 0;
    if(n > 0) mx = max(mx, LCS(a, b, n-1, m));
    if(m > 0) mx = max(mx, LCS(a, b, n, m-1));
    if(a[n] == b[m]) mx = max(mx, LCS(a, b, n-1, m-1)+1);
    return mx;
}

int main()
{
    string a, b; cin >> a >> b;
    int n = a.size()-1, m = b.size()-1;
    int sol = LCS(a, b, n, m);
    cout << sol << "\n";
}
