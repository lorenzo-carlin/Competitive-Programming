#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    vector<pair<int,int>> moves;

    auto move = [&] (int i, int j) -> void {
        if(j > n-3) {
            cout << "Errore con gli indici dello swap! (j not enough)\n";
            return;
        }
        if(i >= j && i <= j+2) {
            cout << "Errore con gli indici dello swap! (i è compreso nell'intervallo di j)\n";
            return;
        }

        array<int,3> tmp = {v[j], v[j+1], v[j+2]};

        if(j > i) {
            for(int k = j-1; k >= i; k--) {
                v[k+3] = v[k];
            }
            v[i] = tmp[0];
            v[i+1] = tmp[1];
            v[i+2] = tmp[2];
            moves.push_back({j, i});
        } else {
            for(int k = j; k < i-3; k++) {
                v[k] = v[k+3];
            }
            v[i-3] = tmp[0];
            v[i-2] = tmp[1];
            v[i-1] = tmp[2];
            moves.push_back({j, i-3});
        }
    };

    auto find = [&] (int val) -> int {
        int idx = -1;
        for(int i = 0; i < n; i++) {
            if(v[i] == val) {
                idx = i;
            }
        }
        return idx;
    };

    auto print = [&] () -> void {
        for(int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    };
    
    for(int i = 0; i < n-5; i++) {
        int idx = find(i+1);
        if(idx == n-1) {
            move(n-5, n-3);
            move(i, n-3);
        } else if(idx == n-2) {
            move(n-5, n-4);
            move(i, n-3);
        } else if(idx != i) {
            move(i, idx);
        }
    }    

    // OB: voglio portare l'elemento minimo all'inizio degli ultimi 5
    int mn_idx = find(n-4);
    if(mn_idx == n-5) {
        // GG!
    } else if(mn_idx == n-4) {
        move(n-5, n-4);
    } else if(mn_idx == n-3) {
        move(n-5, n-3);
    } else if(mn_idx == n-2) {
        move(n-5, n-3);
        move(n-5, n-4);
    } else if(mn_idx == n-1) {
        move(n-5, n-3);
        move(n-5, n-3);
    }

    // OB: voglio portare il secondo minimo all'inizio
    mn_idx = find(n-3);
    if(mn_idx == n-4) {
        // GG!
    } else if(mn_idx == n-3) {
        move(n-4, n-3);
    } else if(mn_idx == n-2) {
        move(n-4, n-3);
        move(n-4, n-3);
    } else if(mn_idx == n-1) {
        move(n, n-4);
    }

    // Gestisco gli ultimi 3 elementi a mano
    if(v[n-3] == n-2 && v[n-2] == n-1 && v[n-1] == n) {
        // GG!
    } else if(v[n-3] == n-2 && v[n-2] == n && v[n-1] == n-1) {
        move(n-1, n-5);
        move(n, n-4);
        move(n, n-5);
        move(n, n-5);
        move(n-5, n-4);
    } else if(v[n-3] == n-1 && v[n-2] == n-2 && v[n-1] == n) {
        move(n, n-5);
        move(n, n-4);
        move(n, n-5);
    } else if(v[n-3] == n-1 && v[n-2] == n && v[n-1] == n-2) {
        move(n, n-4);
        move(n-5, n-3);
        move(n-5, n-4);
        move(n-5, n-3);
    } else if(v[n-3] == n && v[n-2] == n-2 && v[n-1] == n-1) {
        move(n, n-5);
        move(n-1, n-5);
        move(n-1, n-5);
    } else if(v[n-3] == n && v[n-2] == n-1 && v[n-1] == n-2) {
        move(n, n-5);
        move(n-5, n-4);
        move(n-5, n-4);
        move(n, n-5);
        move(n, n-4);
        move(n, n-5);
    }

    cout << moves.size() << "\n";
    for(auto [x, y]: moves) {
        cout << x+1 << " " << y+1 << "\n";
    }
}