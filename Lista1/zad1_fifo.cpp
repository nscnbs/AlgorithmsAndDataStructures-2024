// Autor: Illia Azler 239537

#include <iostream>
#include <cstdlib>

#define MAX_SIZE 150
using namespace std;

int tab[MAX_SIZE], m = 0, n = -1, randnum = 0;

/**
 * usunięcie elementu
 * @return
 */
inline bool pop_back()
{
	if (m == n)
	{
		cout << "Pusta kolejka";
		return false;
	}

	cout << "Usunieto [" << m + 1 << "]: " << tab[m] << "\n";
	++m;
	return true;
};

/**
 * dodanie elementu
 * @param i element
 * @return
 */
inline bool push_back(int i)
{
	if (n == MAX_SIZE)
	{
		cout << "Nie ma miejsca w tablicy";
		return false;
	}

	tab[n++] = i;
	cout << "Dodano [" << n << "]: " << i << "\n";
	return true;
};

int main()
{
	printf("Zadanie 1 FIFO:\n");
	for (int j = 0; j < 50; j++)
	{
		randnum = 1 + rand() % ((1000 - 1) + 1);
		if (!push_back(randnum))
			cout << "\n";
	}

	for (int j = 0; j < n + 1; j++)
	{
		if (!pop_back())
			cout << "\n";
	}

	return 0;
}