#include <bits/stdc++.h>
using namespace std;

int n, m;

int find(int num, vector<int> &father)
{
    if(father[num] != num)
    {
        father[num] = find(father[num], father);
    }
    return father[num];
}

void unite(int a, int b, vector<int> &father, vector<int> &sum_el, vector<int> &num_el)
{
    int rA = find(a, father);
    int rB = find(b, father);

    father[rA] = rB;
    sum_el[rB] += sum_el[rA];
    num_el[rB] += num_el[rA];
}

void move(int a, int b, vector<int> &father, vector<int> &sum_el, vector<int> &num_el)
{
    sum_el[find(a, father)] -= a;
    num_el[find(a, father)]--;
    if(father[a] == a)
    {
        for(int i = 0; i <= n; ++i)
        {
            if(i != a && find(i, father) == find(a, father))
            {
                father[a] = i;
                father[i] = i;
                num_el[i] = num_el[a];
                sum_el[i] = sum_el[a];
                break;
            }
        }
    }
    for(int i = 0; i <= n; ++i)
    {
        find(i, father);
    }
    father[a] = find(b, father);
    sum_el[father[a]] += a;
    num_el[father[a]]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<int> father(n+1);
    vector<int> num_el(n+1, 1);
    vector<int> sum_el(n+1);

    for(int i = 0; i <= n; ++i)
    {
        father[i] = i;
        sum_el[i] = i;
    }

    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a;
        if(a == 1)
        {
            cin >> b >> c;
            if(find(b, father) != find(c, father))
            {
                unite(b, c, father, sum_el, num_el);
            } 
        } else if(a == 2)
        {
            cin >> b >> c;
            if(find(b, father) != find(c, father))
            {
                move(b, c, father, sum_el, num_el);
            }
        } else if(a == 3)
        {
            cin >> b;
            cout << num_el[find(b, father)] << " " << sum_el[find(b, father)] << "\n";
        }
    }
}