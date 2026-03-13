#include <bits/stdc++.h>
using namespace std;

vector<int> father;
map<int,set<int>> sons;
vector<int> sums;
vector<int> num;

int find(int num)
{
    if(father[num] != num)
    {
        father[num] = find(father[num]);
        sons[father[num]].insert(num);
    }
    return father[num];
}

void unite(int a, int b)
{
    int A = find(a);
    int B = find(b);
    father[A] = B;
    sons[B].insert(A);
    sums[B] += sums[A];
    num[B] += num[A];
}

void move(int a, int b)
{
    int A = find(a);
    int B = find(b);
    num[A]--;
    sums[A] -= a;
    num[B]++;
    sums[B] += a;
    if(father[a] != a)
    {
        for(auto el: sons[a])
        {
            sons[father[a]].insert(el);
            father[el] = father[a];
        }
        sons[a].clear();
    } else if(!sons[a].empty())
    {
        auto it = sons[a].begin();
        int new_f = *it;
        for(auto el: sons[a])
        {
            father[el] = new_f;
        }
        sons[a].clear();
    }
    father[a] = B;
}

void print(int n)
{
    int r = find(n);
    cout << num[r] << " " << sums[r] << "\n";
}

int main()
{
    int n, m; cin >> n >> m;

    for(int i = 0; i <= n; ++i)
    {
        father.push_back(i);
        sums.push_back(i);
    }
    num.resize(n, 1);

    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a;
        if(a == 1)
        {
            cin >> b >> c;
            if(find(b) != find(c))
            {
                unite(b, c);
            } 
        } else if(a == 2)
        {
            cin >> b >> c;
            if(find(b) != find(c))
            {
                move(b, c);
            }
        } else if(a == 3)
        {
            cin >> b;
            print(b);
        }
    }
}