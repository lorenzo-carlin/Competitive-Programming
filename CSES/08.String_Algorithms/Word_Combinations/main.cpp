#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;

struct TrieNode
{
	TrieNode *children[26];
	bool EndOfWord;

	TrieNode()
	{
		for(int i = 0; i < 26; ++i) children[i] = nullptr;
		EndOfWord = false;
	}
};

struct Trie
{
	TrieNode *root;

	void insert(string s)
	{
		TrieNode *curr = root;
		for(char c: s)
		{
			if(curr->children[c-'a'] == nullptr)
			{
				curr->children[c-'a'] = new TrieNode();
			}
			curr = curr->children[c-'a'];
		}
		curr->EndOfWord = true;
	}

	bool search(string s)
	{
		TrieNode *curr = root;
		for(char c: s)
		{
			if(curr->children[c-'a'] == nullptr)
			{
				return false;
			}
			curr = curr->children[c-'a'];
		}
		return curr->EndOfWord;
	}

	Trie()
	{
		root = new TrieNode();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	int sz = s.size();
	Trie trie = Trie();

	int n; cin >> n;
	while(n--)
	{
		string buf; cin >> buf;
		trie.insert(buf);
	}

	vector<ll> dp(sz+1, 0);
	dp[sz] = 1;
	for(int i = sz-1; i >= 0; i--)
	{
		TrieNode *tmp = new TrieNode();
		tmp = trie.root;
		for(int j = i; j < sz; j++)
		{
			if(tmp->children[s[j]-'a'] == nullptr)
			{
				break;
			}
			tmp = tmp->children[s[j]-'a'];
			if(tmp->EndOfWord)
			{
				dp[i] += dp[j+1];
				dp[i] %= mod;
			}
		}
	}

	cout << dp[0] << "\n";
}
