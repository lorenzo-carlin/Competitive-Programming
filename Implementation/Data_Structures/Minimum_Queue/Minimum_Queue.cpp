/*
Now we want to achieve the same operations with a queue,
i.e. we want to add elements at the end and remove them from the front.

Here we consider a simple method for modifying a queue.
It has a big disadvantage though, because the modified queue will actually not store all elements.
*/

#include <bits/stdc++.h>
using namespace std;

void add_element(int el, deque<int> &q)
{
    while(!q.empty() && q.back() > el)
    {
        q.pop_back();
    }
    q.push_back(el);
}

void remove_element(int el, deque<int> &q)
{
    if(!q.empty() && q.front() == el)
    {
        q.pop_front();
    }
    q.pop_front();
}

int find_minimum(deque<int> &q)
{
    return q.front();     
}

int main()
{
    deque<int> q;
    add_element(5, q);
    add_element(7, q);
    cout << find_minimum(q) << "\n";
    add_element(3, q);
    cout << find_minimum(q) << "\n";
    remove_element(3, q);
    cout << find_minimum(q) << "\n";
}