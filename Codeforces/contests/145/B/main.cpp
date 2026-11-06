#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;

    auto check = [&](string s) -> bool {
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '4') c1++;
            else c2++;

            if (i > 0) {
                if (s[i - 1] == '4' && s[i] == '7') c3++;
                if (s[i - 1] == '7' && s[i] == '4') c4++;
            }
        }

        return c1 == a1 && c2 == a2 && c3 == a3 && c4 == a4;
    };

    string ans;
    if(a3 == a4) {

        if(a1 > a3) {
            int x = a1 - a3 - 1;
            int y = a2 - a4;

            if(x < 0 || y < 0) {
                cout << -1 << "\n";
                return 0;
            }

            for(int i = 0; i < x+1; i++) {
                ans += '4';
            }
            for(int i = 0; i < a4-1; i++) {
                ans += "74";
            }
            for(int i = 0; i < y+1; i++) {
                ans += '7';
            }
            ans += '4';
        } else if(a1 == a3) {
            int y = a2 - a4;

            if(y < 0) {
                cout << -1 << "\n";
                return 0;
            }

            for(int i = 0; i < a4; i++) {
                ans += "74";
            }
            for(int i = 0; i < y; i++) {
                ans += '7';
            }
        } else {
            cout << -1 << "\n";
            return 0;
        }
    } else if(a4 == a3+1) {
        int x = a1 - a3 - 1;
        int y = a2 - a4;

        if(x < 0 || y < 0) {
            cout << -1 << "\n";
            return 0;
        }

        ans += '7';
        for(int i = 0; i < x; i++) {
            ans += '4';
        }
        for(int i = 0; i < a3; i++) {
            ans += "47";
        }
        for(int i = 0; i < y; i++) {
            ans += '7';
        }
        ans += '4';
    } else if(a3 == a4+1) {
        int x = a1 - a3;
        int y = a2 - a4 - 1;

        if(x < 0 || y < 0) {
            cout << -1 << "\n";
            return 0;
        }

        for(int i = 0; i < x; i++) {
            ans += '4';
        }
        for(int i = 0; i < a3; i++) {
            ans += "47";
        }
        for(int i = 0; i < y; i++) {
            ans += '7';
        }
    } else {
        cout << -1 << "\n";
        return 0;
    }

    if(check(ans)) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }
}