#include <stack>
using namespace std;

int main()
{
    // DICHIARAZIONE
    stack<int> st;

    // AGGIUNTA ELEMENTO IN CODA
    st.push(17);

    // RIMOZIONE ELEMENTO IN CODA
    st.pop();

    // ULTIMO ELEMENTO
    int last = st.top();
}