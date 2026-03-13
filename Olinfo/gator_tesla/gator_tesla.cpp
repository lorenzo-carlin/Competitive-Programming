#include <bits/stdc++.h>
using namespace std;

bool cond = false;
vector<int> v;
int st;
int n;

void dfs(int pos, int rem)
{
    rem += v[pos];
    if(rem < 10) return;
    if(rem == 10 && pos==st-1)
    {
        cout << pos+2 << "\n";
        cond = true;
        return;
    }
    dfs((pos+1)%n, rem-10);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        v.push_back(a);
    }

    for(int i = 0; i < n; ++i)
    {
        st = i;
        dfs(i,0);
        if(cond == true)
        {
            break;
        }
    }
}