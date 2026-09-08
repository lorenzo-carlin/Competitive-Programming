/*
 * Z-Function
 * Computes for each position the length of the longest substring starting there
 * that matches the prefix of the string, enabling efficient pattern matching.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Naive approach: O(N^2)
vector<int> Z_function_1(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    for(int i = 1; i < n; i++) {
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
    }
    
    return z;
}

// Optimized approach: O(N)
vector<int> Z_function_2(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r-i, z[i-l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

int main()
{
    string s; cin >> s;
    vector<int> v = Z_function_2(s);
    for(int el: v) cout << el << " ";
    cout << "\n";
}
