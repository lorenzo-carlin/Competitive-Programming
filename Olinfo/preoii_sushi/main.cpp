#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int n, b;
int mx = 1e9;
vector<int> v, t;
map<int,int> mp;

void solve(int curr)
{
    if(curr == b)
    {
        mx = min(mx, -(*mp.begin()).first);
        return;
    }
    if(curr > b) return;
    
    for(int i = 0; i < n; ++i)
    {
        mp[-t[i]]--;
        t[i]++;
        mp[-t[i]]++;
        solve(curr+v[i]);
        mp[-t[i]]--;
        if(mp[-t[i]] == 0) mp.erase(-t[i]);
        t[i]--;
        mp[-t[i]]++;
    }

}

int sushi(int N, int B, vector<int> A)
{
	n = N, b = B, v = A;
    t.resize(n, 0);
    mp[0] = n;

    solve(0);

    if(mx == 1e9) mx = -1;
    return mx;
}
