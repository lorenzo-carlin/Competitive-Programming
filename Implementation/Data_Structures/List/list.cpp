#include <list>
using namespace std;

int main()
{
    // DICHIARAZIONE
    list<int> l(15, 0);

    // AGGIUNTA ELEMENTO IN TESTA - O(1)
    l.push_front(10);

    // AGGIUNTA ELEMENTO IN CODA - O(1)
    l.push_back(7);

    // ACCESSO AL PRIMO ELEMENTO - O(1)
    int first = l.front();

    // ACCESSO ALL'ULTIMO ELEMENTO - O(1)
    int last = l.back();

    // RIMOZIONE ELEMENTO IN TESTA - O(1)
    l.pop_front();

    // RIMOZIONE ELEMENTO IN COSA - O(1)
    l.pop_back();

    // AGGIUNTA ELEMENTO IN UNA QUALSIASI POSIZIONE (ad es. 3°) - O(N)
    auto it = l.begin();
    for(int i = 0; i < 3; ++i) it++;
    l.insert(it, 13);

    // RIMOZIONE ELEMENTO IN UNA QUALSIASI POSIZIONE (ad es. 3°) - O(N)
    auto it = l.begin();
    for(int i = 0; i < 3; ++i) it++;
    l.erase(it);

    // SVUOTAMENTO DELLA LISTA - O(N)
    l.clear();
}