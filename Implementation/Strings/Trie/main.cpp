/*
 * Trie
 * Stores strings in a prefix tree, supporting efficient insertion, search,
 * and prefix queries in O(L) time, where L is the string length.
 */


#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool EndOfWord;
    
    TrieNode ()
    {
        EndOfWord = false;
        for(int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
    }
};

void insertKey(TrieNode *root, string key)
{
    TrieNode *cur = root;

    for(char c: key)
    {
        if(cur->children[c-'a'] == nullptr)
        {
            TrieNode *newNode = new TrieNode();
            cur->children[c-'a'] = newNode;
        }
        cur = cur->children[c-'a'];
    }
    cur->EndOfWord = true;
}

bool searchKey(TrieNode *root, string key)
{
    TrieNode *cur = root;

    for(char c: key)
    {
        if(cur->children[c-'a'] == nullptr)
        {
            return false;
        }
        cur = cur->children[c-'a'];
    }
    return cur->EndOfWord;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
