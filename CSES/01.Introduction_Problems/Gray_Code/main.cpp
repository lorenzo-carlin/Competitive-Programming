#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
 
    vector<string> arr;
    arr.push_back("0");
    arr.push_back("1");
 
    for(int i = 1; i < n; ++i)
    {
        int pot = pow(2, i);
        for(int j = pot-1; j >= 0; j--) arr.push_back(arr[j]);
 
        for(int j = 0; j < pot; ++j) arr[j] = "0" + arr[j];
        for(int j = pot; j < 2*pot; ++j) arr[j] = "1" + arr[j];
    }
 
    for(auto el: arr) cout << el << "\n";
}
