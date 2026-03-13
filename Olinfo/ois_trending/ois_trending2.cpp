#include <bits/stdc++.h>
using namespace std;

map<string,int> word_cnt;
map<int,set<string>> cnt_word;
deque<string> dq;
int mx = 0;

void erase_el()
{
    string er = dq.front();
    dq.pop_front();
    word_cnt[er]--;
    int tmp = word_cnt[er];
    cnt_word[tmp+1].erase(er);
    cnt_word[tmp].insert(er);
}

void add_el(string el)
{
    dq.push_back(el);
    word_cnt[el]++;
    int tmp = word_cnt[el];
    if(tmp > mx) mx = tmp;
    cnt_word[tmp].insert(el);
    cnt_word[tmp-1].erase(el);
}

void print_mx()
{
    auto it = cnt_word.find(mx);
    while(it == cnt_word.end())
    {
        mx--;
        it = cnt_word.find(mx);
    }
    auto ans = cnt_word[mx].begin();
    cout << *ans << "\n";
}

int main()
{
    int n, m; cin >> n >> m;
    
    // parte 1: condizione iniziale
    string s;
    for(int i = 0; i < m; ++i)
    {
        cin >> s;
        dq.push_back(s);
        word_cnt[s]++;
        int tmp = word_cnt[s];
        if(tmp > mx) mx = tmp;
        cnt_word[tmp].insert(s);
        if(tmp!=1) cnt_word[tmp-1].erase(s);
    }
    auto it = cnt_word[mx].begin();
    cout << *it << "\n";

    // parte 2: resto dell'input
    for(int i = m; i < n; ++i)
    {
        cin >> s;
        erase_el();
        add_el(s);
        print_mx();
    }
}