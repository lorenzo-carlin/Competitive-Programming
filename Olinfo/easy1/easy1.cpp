#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N; cin >> N;
    int a[N];
    for(auto &i: a) cin >> i;
    cout << *max_element(a, a+N);
}