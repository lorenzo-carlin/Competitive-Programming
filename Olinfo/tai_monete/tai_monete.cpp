#include <bits/stdc++.h>
#pragma GCC optimize("03")
#pragma GCC target("avx2")
using namespace std;

int best_score(int N, int K, vector<int> &monete)
{
    deque<pair<int,int>> min_pq;
    min_pq.push_back({0, -1});

    int ps = 0, sol;

    for(int i = 0; i < N; i++)
    {
        ps += monete[i];
        if(!min_pq.empty() && min_pq.front().second < i-K) min_pq.pop_front();
        sol = ps - min_pq.front().first;
        while(!min_pq.empty() && min_pq.back().first > sol) min_pq.pop_back();
        min_pq.push_back({sol, i});
    }

    return sol;
}

int main()
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &el: v) cin >> el;
    cout << best_score(n, k, v) << "\n";
}