#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;

    cin >> n >> s;

    stack<int> st;
    vector<bool> vis(n+1, false);

    for(int i = 1; i <= n; i++) {
        if(s[i-1] == '1') {
            st.push(i);
        } else if(s[i-1] == '2') {
            if(!st.empty()) {
                vis[st.top()] = true;
                st.pop();
            } else {
                vis[i] = true;
            }
        } else {
            vis[i] = true;
        }
    }

    vector<int> ans;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";

    for(int el: ans) {
        cout << el << " ";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}