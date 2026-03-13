#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<long long> v;
    for(int i = 0; i < n; ++i)
    {
        long long tmp; cin >> tmp;
        v.insert(v.end(), tmp);
    }
    sort(v.begin(), v.end());
    int ris = 1;
    for(int i = 1; i < n; ++i)
    {
        if(v[i] != v[i-1])
        {
            ris++;
        }
    }
    cout << ris;
    return 0;
}