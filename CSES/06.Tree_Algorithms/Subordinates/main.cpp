#include <bits/stdc++.h>
using namespace std;

int countSub(int emp, map<int,set<int>> &tree, vector<int> &sub)
{
    if(sub[emp] != -1) return sub[emp];
    int ris = 0;
    for(auto el: tree[emp])
    {
        ris += (countSub(el, tree, sub)+1);
    }
    sub[emp] = ris;
    return ris;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int,set<int>> tree;

    int n, a; cin >> n;
    for(int i = 2; i <= n; ++i)
    {
        cin >> a;
        tree[a].insert(i);
    }

    vector<int> sub(n+1, -1);

    countSub(1, tree, sub);
    for(int i = 1; i <= n; ++i)
    {
        cout << sub[i] << " ";
    }
    
    cout << "\n";
}