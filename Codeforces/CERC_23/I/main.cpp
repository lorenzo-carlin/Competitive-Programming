#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    auto Ask = [&](vector<int> &v) {
        cout << "QUERY ";
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
        vector<int> deg(n);
        for (int i = 0; i < n; ++i) {
            cin >> deg[i];
        }
        return deg;
    };

    vector<vector<int>> g(n);
    vector<pair<int, int>> edges;
    auto Ans = [&]() {
        cout << "ANSWER" << endl;
        for (auto [u, v] : edges) {
            cout << u + 1 << " " << v + 1 << endl;
        }
    };

    vector<int> v(n, 1);
    auto deg = Ask(v);

    vector<int> ord(n);

}