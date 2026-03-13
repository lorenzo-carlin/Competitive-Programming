#include <bits/stdc++.h>
using namespace std;

bool control(vector<pair<pair<int,int>,int>> &v, int i, int j)
{
    float sum_r = (float) v[i].second + v[j].second;
    float dif_r = (float) abs(v[i].second - v[j].second);
    float dist_c = sqrt(pow((v[i].first.first)-(v[j].first.first),2) + pow((v[i].first.second)-(v[j].first.second),2));
    if(sum_r >= dist_c && dif_r <= dist_c) return true;
    return false;
}

bool point(int x, int y, int xc, int yc, int r)
{
    float dist_p = sqrt(pow(x-xc,2) + pow(y-yc,2));
    if(dist_p == r) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int st = -1, fn = -1;

    vector<pair<pair<int,int>,int>> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            if(control(v, i, j))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        if(point(x1, y1, v[i].first.first, v[i].first.second, v[i].second))
        {
            st = i;
            break;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        if(point(x2, y2, v[i].first.first, v[i].first.second, v[i].second))
        {
            fn = i;
            break;
        }
    }

    // risoluzione
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(st);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = true;

        for(auto el: adj[x])
        {
            if(el == fn)
            {
                cout << "Yes\n";
                return 0;
            }
            if(!vis[el])
            {
                q.push(el);
            }
        }
    }

    if(vis[fn])
    {
        cout << "Yes\n";
    } else
    {
        cout << "No\n";
    }
    return 0;
}