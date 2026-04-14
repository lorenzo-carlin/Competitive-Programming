#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://stackoverflow.com/questions/5888022/split-string-by-single-spaces
size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

#include <map>
#include <set>

int main() {
    string s;
    cin >> s;
    if (s == "ENCODE") {
        string line;
        map<string, int> inDeg;
        map<string, vector<string>> mp;
            
        while (getline(cin, line)) {
            vector<string> strs; 
            split(line, strs, ' ');
            strs[0].pop_back();
            
            for (int i = 1; i < int(strs.size()); ++i) {
                mp[strs[0]].push_back(strs[i]);
                inDeg[strs[i]] += 1;
            }
        }

        // print all str
        string root = "";
        for (auto &[s, _] : mp) {
            if (!inDeg.count(s)) {
                root = s;
                break;
            }
        }

        string ord = "";
        auto dfs = [&](auto &&self, string node) -> void {
            cout << node << "\n";
            ord.push_back('0');
            ord.push_back('1');
            for (auto &to : mp[node]) {
                self(self, to);
            }
            ord.push_back('1');
        };

        dfs(dfs, root);
        cout << ord << '\n';
    }  else {
        string line;
        string ord;
        vector<string> names;
        while (getline(cin, line)) {
            if (line == "") {
                continue;
            }
            if (line[0] == '0') {
                ord = line;
            } else {
                names.push_back(line);
            }
        }

        // for (int i = 0; i < int(names.size()); ++i) {
        //     cout << i << " --> " << names[i] << '\n';
        // }

        map<string, vector<string>> mp;
        auto isLeaf = [&](int i) {
            return ord[i] == '0' && ord[i + 1] == '1' && ord[i + 2] == '1';
        };

        int i = 0;
        int idx = 0;
        auto dfs = [&](auto &&self, string node) -> void {
            if (isLeaf(i)) {
                i += 3;
                return; // don't do
            }

            // go children
            i += 2;
            while (i < ord.length() && ord[i] == '0') { // has children
                // create a new node
                ++idx;
                mp[node].push_back(names[idx]);
                self(self, names[idx]);
            }
        };

        // print the tree
        dfs(dfs, names[0]);
        for (string key : names) {
            if (mp.count(key)) {
                auto &vec = mp[key];
                cout << key << ": ";
                for (auto s : vec) {
                    cout << s << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}