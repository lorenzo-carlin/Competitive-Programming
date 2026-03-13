#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N), B(N), C(N);
        long long SA_tot = 0, SB_tot = 0, SC_tot = 0;

        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i] >> C[i];
            SA_tot += A[i];
            SB_tot += B[i];
            SC_tot += C[i];
        }

        long long needA = (SA_tot + 1) / 2;
        long long needB = (SB_tot + 1) / 2;
        long long needC = (SC_tot + 1) / 2;

        vector<int> idxA(N), idxB(N), idxC(N);
        iota(idxA.begin(), idxA.end(), 0);
        iota(idxB.begin(), idxB.end(), 0);
        iota(idxC.begin(), idxC.end(), 0);

        sort(idxA.begin(), idxA.end(), [&](int i, int j) {
            return A[i] > A[j];
        });
        sort(idxB.begin(), idxB.end(), [&](int i, int j) {
            return B[i] > B[j];
        });
        sort(idxC.begin(), idxC.end(), [&](int i, int j) {
            return C[i] > C[j];
        });

        vector<bool> chosen(N, false);

        long long sum = 0;
        for (int i : idxA) {
            if (sum >= needA) break;
            chosen[i] = true;
            sum += A[i];
        }

        sum = 0;
        for (int i : idxB) {
            if (sum >= needB) break;
            chosen[i] = true;
            sum += B[i];
        }

        sum = 0;
        for (int i : idxC) {
            if (sum >= needC) break;
            chosen[i] = true;
            sum += C[i];
        }

        vector<int> result;
        for (int i = 0; i < N; i++) {
            if (chosen[i]) result.push_back(i);
        }

        cout << result.size() << "\n";
        for (int i : result) cout << i << " ";
        cout << "\n";
    }
}

