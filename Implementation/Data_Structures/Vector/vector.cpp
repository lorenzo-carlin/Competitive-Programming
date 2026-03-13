#include <vector>
#include <algorithm>        // per il sort()
#include <iostream>
using namespace std;

int main()
{
    // dichiarazione di un vector
    vector<int> v(5, 0);    // tra parentesi (numero elementi, valore d'inizio di tutti gli elementi)

    // aggiungere valori in fondo - O(1)
    v.push_back(15);        // v.push_back(nr da inserire)
    v.push_back(30);
    
    // aggiungere valori da qualsiasi parte - O(n)
    v.insert(v.begin()+2, 0);

    // rimuovere elemento in fondo - O(1)
    v.pop_back();

    // rimuovere valori da qualsiasi parte - O(n)
    v.erase(v.begin()+3);

    // scambiare due elementi - O(1)
    swap(v[0], v[1]);

    // svuotare il vector - O(n)
    v.clear();

    // accesso all'elemento iniziale - O(1)
    v.front();
    cout << v.front() << "\n";

    // accesso all'ultimo elemento - O(1)
    v.back();
    cout << v.back() << "\n";

    // ordinare un vector in modo crescente - O(n*log(n))
    sort(v.begin(), v.end());

    // ordinare un vector in modo decrescente - O(n*log(n))
    sort(v.rbegin(), v.rend());

    // creare vector di vector (simili alle matrici) e come utilizzarli
    vector<vector<int>> adj(5);
    cout << adj[0][1] << "\n";
    adj.push_back({1, 2, 3});       // inserisco un vector intero in adj
    adj[4].push_back(3);            // inserisco un elemento di adj[4]
    adj[4].pop_back();    
}