#include <iostream>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    int d = b - a;
    if(d==1 || d == 9)
        cout << "Yes";
    else
        cout << "No";
}