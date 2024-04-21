// Autor: Illia Azler 239537

#include <iostream>
#include <cstdlib>

#define MAX_SIZE 150
using namespace std;

int tab[MAX_SIZE], m = 0, randnum = 0;

inline bool push(int element)
{
    if (m >= MAX_SIZE)
    {
        cout << "Nie ma miejsca w tablicy";
        return false;
    }

    cout << "Dodano [" << m << "]: " << element << "\n";
    tab[m++] = element;
    return true;
}

inline int pop()
{
    if (m < 0)
    {
        cout << "Pusta kolejka";
        return 0;
    }
    if (m == 50)
        --m;

    cout << "Usunieto [" << m << "]: " << tab[m] << "\n";
    --m;
    return 1;
}

int main()
{
    printf("Zadanie 1 LIFO:\n");
    for (int j = 0; j < 50; j++)
    {
        randnum = 1 + rand() % ((1000 - 1) + 1);
        if (!push(randnum))
            cout << "\n";
    }

    for (int j = m + 1; j > 0; j--)
    {
        if (!pop())
            cout << "\n";
    }
}