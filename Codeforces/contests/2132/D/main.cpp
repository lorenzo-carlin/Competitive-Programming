#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

long long sumDigits(long long x) {
    if (x <= 0) return 0;
    if (x < 10) return x * (x + 1) / 2;

    string s = to_string(x);
    int k = (int)s.size() - 1; 
    long long p = 1;
    for (int i = 0; i < k; i++) p *= 10;

    int d = s[0] - '0';
    long long r = x - 1LL * d * p;

    auto S = [&](int k) -> long long {
        if (k == 0) return 0LL;
        long long res = 1;
        for (int i = 0; i < k - 1; i++) res *= 10;
        return 1LL * k * 45 * res;
    };

    long long res = 0;
    res += 1LL * d * S(k);
    res += 1LL * (d * (d - 1) / 2) * p;
    res += 1LL * d * (r + 1);
    res += sumDigits(r);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;

        long long ans = 0;
        int len = 1;
        long long cnt = 9;
        while (true) {
            long long blockDigits = 1LL * len * cnt;
            if (k > blockDigits) { // tutto
                long long L = (len == 1 ? 1 : (long long)pow(10, len - 1));
                long long R = (long long)pow(10, len) - 1;
                ans += sumDigits(R) - sumDigits(L - 1);
                k -= blockDigits;
                len++;
                cnt *= 10;
            } else { // questo
                long long fullNums = k / len;
                long long extraDigits = k % len;

                long long start = (len == 1 ? 1 : (long long)pow(10, len - 1));
                long long upto = start + fullNums - 1;

                if (fullNums > 0)
                    ans += sumDigits(upto) - sumDigits(start - 1);

                if (extraDigits > 0) {
                    long long nextNum = start + fullNums;
                    string s = to_string(nextNum);
                    for (int i = 0; i < extraDigits; i++)
                        ans += s[i] - '0';
                }

                break;
            }
        }
        cout << ans << "\n";
    }
}
