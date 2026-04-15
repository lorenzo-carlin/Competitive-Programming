#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        bool solved = false;
        int n, x; cin >> n >> x;
        vector<int> v(n);
        for(auto &i: v) cin >> i;
        sort(v.begin(), v.end());

        int sum = 0, sol = 1;
        for(int i = 0; i < n-1; i++)
        {
            int gap = (v[i+1]-v[i])*(i+1);
            if(sum + gap <= x)
            {
                sum += gap;
                sol = v[i+1];
            } else
            {
                int tmp = x - sum;
                sol += (tmp/(i+1));
                solved = true;
                break;
            }
        }
        if(!solved)
        {
            sol += (x-sum)/n;
        }
        cout << sol << "\n";
    }
}
