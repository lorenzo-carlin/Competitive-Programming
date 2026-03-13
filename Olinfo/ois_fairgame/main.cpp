#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    ll M, P, Q;
    cin >> N >> K >> M >> P >> Q;

    vector<ll> dp0(N+1), dp1(N+1);

    dp0[0] = Q - P;
    dp1[0] = P - Q;

    deque<int> even1_max, odd1_max;
    deque<int> even0_min, odd0_min;

    even1_max.push_back(0);
    even0_min.push_back(0);

    for(int i = 1; i <= N; i++){
        int L = max(0, i - K);

        auto pop_old = [&](deque<int>& d){
            while(!d.empty() && d.front() < L) d.pop_front();
        };

        pop_old(even1_max);
        pop_old(odd1_max);
        pop_old(even0_min);
        pop_old(odd0_min);

        ll best0 = LLONG_MIN;
        ll best1 = LLONG_MAX;

        if(i % 2 == 0){
            if(!even1_max.empty()) best0 = max(best0, dp1[even1_max.front()]);
            if(!odd1_max.empty())  best0 = max(best0, dp1[odd1_max.front()] - M);

            if(!even0_min.empty()) best1 = min(best1, dp0[even0_min.front()]);
            if(!odd0_min.empty())  best1 = min(best1, dp0[odd0_min.front()] + M);
        } else {
            if(!odd1_max.empty())  best0 = max(best0, dp1[odd1_max.front()]);
            if(!even1_max.empty()) best0 = max(best0, dp1[even1_max.front()] - M);

            if(!odd0_min.empty())  best1 = min(best1, dp0[odd0_min.front()]);
            if(!even0_min.empty()) best1 = min(best1, dp0[even0_min.front()] + M);
        }

        dp0[i] = best0;
        dp1[i] = best1;

        auto push_max = [&](deque<int>& d, ll val, vector<ll>& ref){
            while(!d.empty() && ref[d.back()] <= val) d.pop_back();
            d.push_back(i);
        };
        auto push_min = [&](deque<int>& d, ll val, vector<ll>& ref){
            while(!d.empty() && ref[d.back()] >= val) d.pop_back();
            d.push_back(i);
        };

        if(i % 2 == 0){
            push_max(even1_max, dp1[i], dp1);
            push_min(even0_min, dp0[i], dp0);
        } else {
            push_max(odd1_max, dp1[i], dp1);
            push_min(odd0_min, dp0[i], dp0);
        }
    }

    cout << dp0[N] << "\n";
}

