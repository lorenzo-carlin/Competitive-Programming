#include <bits/stdc++.h>
using namespace std;

int n, b;
int mx = 1e9;
vector<int> v, t;
map<int,int> mp;

const int MAXN = 1e4+5;
const int MAXB = 1e5+5;
int memo[MAXN][MAXB];
bool vis[MAXN][MAXB];

int solve(int ind, int curr)
{
    if(ind >= n) return 1e9;
    if(curr == b) return -(*mp.begin()).first;

    if(vis[ind][curr]) return memo[ind][curr];
    vis[ind][curr] = true;

    int mn = 1e9;

    // prendo (se posso)
    if(curr + v[ind] <= b)
    {
        mp[-t[ind]]--;
        t[ind]++;
        mp[-t[ind]]++;
        mn = min(mn, solve(ind, curr+v[ind]));
        mp[-t[ind]]--;
        if(mp[-t[ind]] == 0) mp.erase(-t[ind]);
        t[ind]--;
        mp[-t[ind]]++;
    }

    // non prendo
    mn = min(mn, solve(ind+1, curr+v[ind]));

    return memo[ind][curr] = mn;
}

int sushi(int N, int B, vector<int> A)
{
    v = A;
    t.resize(n, 0);
    mp[0] = n;

    int sol = solve(0, 0);

    if(sol == 1e9) sol = -1;
    return sol;
}

int main()
{
    cin >> n >> b;
    vector<int> A;
    for(int i = 0; i < n; ++i)
    {
        int tmp; cin >> tmp;
        A.push_back(tmp);
    }

    cout << sushi(n, b, A) << "\n";
}




// void solve(int curr)
// {
//     if(curr == b)
//     {
//         mx = min(mx, -(*mp.begin()).first);
//         return;
//     }
//     if(curr > b) return;
    
//     for(int i = 0; i < n; ++i)
//     {
//         mp[-t[i]]--;
//         t[i]++;
//         mp[-t[i]]++;
//         solve(curr+v[i]);
//         mp[-t[i]]--;
//         if(mp[-t[i]] == 0) mp.erase(-t[i]);
//         t[i]--;
//         mp[-t[i]]++;
//     }

// }