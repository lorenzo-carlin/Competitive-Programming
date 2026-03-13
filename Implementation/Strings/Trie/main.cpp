#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int K = 26;

struct Vertex
{
    int n[K];
    bool flag = false;

    Vertex()
    {
        fill(begin(n), end(n), -1);
    }
};

vector<Vertex> trie(1);

void add(string s)
{
    int idx = 0;
    for(char c: s)
    {
        int x = c - 'a';
        if(trie[idx].n[x] == -1)
        {
            trie[idx].n[x] = trie.size();
            trie.emplace_back();
        }
        idx = trie[idx].n[x];
    }
    trie[idx].flag = true;
}

bool search(string s)
{
    int idx = 0;
    for(char c: s)
    {
        int x = c - 'a';
        if(trie[idx].n[x] == -1)
        {
            return false;
        }
        idx = trie[idx].n[x];
    }
    return trie[idx].flag;
}
