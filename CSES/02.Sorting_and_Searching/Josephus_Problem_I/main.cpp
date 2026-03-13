#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
    
    vector<int> v(n);
    iota(begin(v), end(v), 1);
 
    vector<int> tmp;
 
    while(v.size() > 1)
    {
        tmp.clear();
        
        if(v.size() % 2) tmp.push_back(v.back());
        for(int i = 0; i < v.size(); ++i)
        {
            if(i & 1)
            {
                cout << v[i] << " ";
            } else
            {
                tmp.push_back(v[i]);
            }
        }
        if(v.size() % 2) tmp.pop_back();
 
        v = tmp;
    }
    cout << v.front() << "\n";
}
