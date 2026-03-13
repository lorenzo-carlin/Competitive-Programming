#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> s >> n;
    if((s == "OCT" && n == 31) || (s == "DEC" && n == 25))
    {
        cout << "yup\n";
    } else
    {

        cout << "nope\n";
    }
}