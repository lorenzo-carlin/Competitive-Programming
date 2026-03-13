#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> father(n);
vector<int> height(n, 0);

// path comrpession: ogni nodo ha come padre la sua radice
int find(int node)
{
    if(father[node] != node)
    {
        father[node] = find(father[node]);
    }
    return father[node];
}

// union by rank
void unite_rank(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    if(height[rootA] > height[rootB])
    {
        father[rootB] = rootA;
        height[rootA] = max(height[rootA], height[rootB+1]);
    } else
    {
        father[rootA] = rootB;
        height[rootB] = max(height[rootB], height[rootA]+1);
    }
}

// randomized linking (+ veloce e facile da ricordare)
void unite_rand(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    if(rand() % 2)
    {
        father[rootB] = rootA;
    } else
    {
        father[rootA] = rootB;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        father[i] = i;
    }
}