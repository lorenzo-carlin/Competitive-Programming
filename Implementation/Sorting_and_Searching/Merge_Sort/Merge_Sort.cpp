#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;
ll inv = 0;

void merge_sort(vector<int> &a)
{
    if(a.size() == 1) return;

    int dimLeft = (a.size()+1)/2;
    int dimRight = a.size()/2;
    vector<int> subLeft(dimLeft), subRight(dimRight);
    for(int i = 0; i < dimLeft; i++)
    {
        subLeft[i] = a[i];
    }
    for(int i = 0; i < dimRight; i++)
    {
        subRight[i] = a[dimLeft+i];
    }
    
    merge_sort(subLeft);
    merge_sort(subRight);

    subLeft.push_back(INF);
    subRight.push_back(INF);

    int l = 0, r = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(subLeft[l] <= subRight[r])
        {
            a[i] = subLeft[l];
            l++;
        } else
        {
            a[i] = subRight[r];
            r++;
            inv += (dimLeft-l);
        }
    }
}

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    merge_sort(v);

    for(int i = 0; i < n; ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";

    cout << inv << " inversioni.\n";
}