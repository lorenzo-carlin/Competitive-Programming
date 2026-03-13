#include<iostream>
using namespace std;

int main()
{
    pair<int,int> p;
    p = make_pair(1, 2);
    cout << p.first << "\n";
    cout << p.second << "\n";

    pair<int,pair<int,int>> p2({1,{2,3}});
    cout << p2.first << "\n";
    cout << p2.second.first << "\n";
    cout << p2.second.second << "\n";
}