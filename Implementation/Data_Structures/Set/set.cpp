#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

/**********************************************************************************
SET:
    - valori ordinati
    - non permette doppioni

MULTISET:
    - valori ordinati
    - permette doppioni
    - attenzione all'erase! (cancella tutti gli elementi con un determinato valore)

UNORDERED SET:
    - valori non ordinati
    - non permette doppioni
    - molto più veloce nelle operazioni
**********************************************************************************/

int main()
{
    // dichiarare di un set (vuoto)
    set<int> s;

    // inserire di valori
    s.insert(5);
    s.insert(5);
    s.insert(3);
    s.insert(10);
    s.insert(6);
    s.insert(7);

    // sintassi per vedere ogni elemento presente nel set
    for(int el: s)
    {
        cout << el << " ";
    }
    cout << "\n";

    // rimuovere un valore
    s.erase(10);

    // contare quanti elementi di un valore sono presenti
    s.count(10);
    cout << s.count(10) << "\n";

    // verificare se un elemento è presente nel set
    // !it è un iteratore
    auto it = s.find(10);
    if(it == s.end())
    {
        cout << "non è presente.\n";
    } else
    {
        cout << "è presente.\n";
    }

    // trovare il primo valore >= a un valore
    auto it2 = s.lower_bound(5);
    cout << *it2 << "\n";

    // trovare il primo valore > a un valore
    auto it3 = s.upper_bound(5);
    cout << *it3 << "\n";

    // spostare un iteratore
    it2--;
    cout << *it2 << "\n";

    cout << "\n";

    // dichiarare un multiset
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    ms.insert(3);

    // eliminare un elemento dal multiset (!elimita tutto gli elementi di quel valore)
    ms.erase(5);
    
    // sintassi per vedere ogni elemento presente nel multiset
    for(int el: ms)
    {
        cout << el << " ";
    }

    // altre funzioni valide per i multiset:
    // find(), count(), swap(), clear(), lower_bound(), upper_bound()

    cout << "\n";
    
    // dichiarare un unordered set
    unordered_set<int> us;

    // inserire valori in un unordered set
    us.insert(5);
    us.insert(6);
    us.insert(3);

    // sintassi per vedere ogni elemento presente nel multiset
    for(int el: us)
    {
        cout << el << " ";
    }

    // altre funzioni valide per gli unordered set:
    // find(), count(), swap(), clear()
}