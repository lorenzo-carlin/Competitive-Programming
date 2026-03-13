#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;

    unordered_set<ll> s;

    for(ll i = 2; i*i <= n; i++)
    {
        ll curr = i*i;
        while(curr <= n)
        {
            s.insert(curr);
            curr *= i;
        }
    }

    cout << n-s.size() << "\n";
}


/*
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <cmath> // sqrt sin cos pow
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <climits> // INT_MAX LONG_MAX
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <functional>
#include <cctype> // isupper, islower, isdigit, toupper, tolower
// #include <atcoder/all> 
// using namespace atcoder;
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n;
    cin >> n;

    unordered_set<ll> st;
    for(ll a = 2; a * a <= n; a++){
        ll x = a * a;
        while(x <= n){
            st.insert(x);
            x *= a;
        }
    }
    cout << n - st.size() << endl;
}
*/