/*
 * Prefix Function
 * Computes the length of the longest proper prefix that is also a suffix
 * for every prefix of a string, as used in the Knuth-Morris-Pratt (KMP) algorithm.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Naive solution: O(N^3)

vector<int> prefix_function_1(string s) {
    int n = s.size();
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(s.substr(0, j) == s.substr(i-j+1, j)) {
                v[i] = j;
            }
        }
    }
    return v;
}

// Better solution: O(N^2)

vector<int> prefix_function_2(string s) {
    int n = s.size();
    vector<int> v(n, 0);
    for(int i = 1; i < n; i++) {
        for(int j = v[i-1]+1; j > 0; j--) {
            if(s.substr(0, j) == s.substr(i-j+1, j)) {
                v[i] = j;
                break;
            }
        }
    }
    return v;
}

// Best solution: O(N)

vector<int> prefix_function_3(string s) {
    int n = s.size();
    vector<int> v(n, 0);
    for(int i = 1; i < n; i++) {
        int x = v[i-1];
        while(x > 0 && s[i] != s[x]) {
            x = v[x-1];
        }
        if(s[i] == s[x]) x++;
        v[i] = x;
    }
    return v;
}        

int main()
{
    string s; cin >> s;

    vector<int> ans;

    ans = prefix_function_1(s);
    for(auto el: ans) cout << el << " ";
    cout << "\n";

    ans = prefix_function_2(s);
    for(auto el: ans) cout << el << " ";
    cout << "\n";

    ans = prefix_function_3(s);
    for(auto el: ans) cout << el << " ";
    cout << "\n";
}
