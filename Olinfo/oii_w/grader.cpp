#include <vector>
#include <iostream>
using namespace std;

long long estrai(int N, long long K, vector<int> A, vector<int> Q);




// GRADER DI ESEMPIO
// NON MODIFICARE AL DI SOTTO DI QUESTA LINEA

#ifndef EVAL
int main() {
    int N;
    long long K;

    cin >> N >> K;

    vector<int> A(N), Q(N);
    for(int &x: A) cin >> x;
    for(int &x: Q) cin >> x;

    cout << estrai(N, K, A, Q) << endl;
}
#endif

