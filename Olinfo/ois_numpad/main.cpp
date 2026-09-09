#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int,int>> cord(10);
    cord[0] = {3, 1};
    cord[1] = {0, 0};
    cord[2] = {0, 1};
    cord[3] = {0, 2};
    cord[4] = {1, 0};
    cord[5] = {1, 1};
    cord[6] = {1, 2};
    cord[7] = {2, 0};
    cord[8] = {2, 1};
    cord[9] = {2, 2};

    int sol = 0;
    string s; cin >> s;
    int prec = 0;
    for(char i: s)
    {
        int el = i-'0';
        sol += abs(cord[el].first-cord[prec].first)+abs(cord[el].second-cord[prec].second)+1;
        prec = el;
    }
    cout << sol << "\n";
}