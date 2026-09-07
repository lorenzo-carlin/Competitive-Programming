/*
 * Minimum Stack
 * Supports efficient insertion, removal, and retrieval of the minimum element.
 */


#include <iostream>
#include <stack>
using namespace std;

void add_element(int el, stack<pair<int,int>> &st)
{
    int new_min = st.empty() ? el : min(el, st.top().second);
    st.push({el, new_min});
}

void remove_element(stack<pair<int,int>> &st)
{
    int removed_el = st.top().first;
    st.pop();
}

int find_minimum(stack<pair<int,int>> &st)
{
    return st.top().second;
}

int main()
{
    stack<pair<int,int>> st;
    add_element(5, st);
    add_element(2, st);
    cout << find_minimum(st) << "\n";
    remove_element(st);
    add_element(3,st);
    cout << find_minimum(st) << "\n";
}
