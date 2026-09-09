#include <iostream>
using namespace std;

int fotosintesi (int N, string S);

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL
int main () {
    string S; cin >> S;

    cout << fotosintesi(S.size(), S) << endl;
}
#endif
