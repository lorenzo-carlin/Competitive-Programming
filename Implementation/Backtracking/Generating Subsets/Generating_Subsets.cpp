/*******************************************
Generates all subsets of a set of n elements
*******************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> subset;

void search(int k, int n, vector<int> &v)
{
    if(k == n)
    {
        for(auto el: subset) cout << el << " ";
        cout << "\n";
    } else
    {
        search(k+1, n, v);
        subset.push_back(v[k]);
        search(k+1, n, v);
        subset.pop_back();
    }
}

int main()
{
    int n; cin >> n;

    vector<int> v(n);
    for(auto &i: v) cin >> i;

    search(0, n, v);

}