#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q; cin >> n >> q;

    vector<int> ranking; ranking.push_back(-1);
    map<int,int> position;
    
    for(int i = 1; i <= n; ++i)
    {
        int car; cin >> car;
        ranking.push_back(car);
        position[car] = i;
    }

    map<int,int> overtaken;

    int mx = 0, mx_car = 200001;
    for(int i = 0; i < q; ++i)
    {
        int car; cin >> car;
        int pos = position[car];
        position[car]--;
        overtaken[ranking[pos-1]]++;
        int car_over = ranking[pos-1];
        position[car_over]++;
        if(overtaken[ranking[pos-1]] > mx || (overtaken[ranking[pos-1]] == mx && car_over < mx_car))
        {
            mx = overtaken[ranking[pos-1]];
            mx_car = car_over;
        }
        swap(ranking[pos], ranking[pos-1]);
        cout << mx_car << "\n";
    }
}