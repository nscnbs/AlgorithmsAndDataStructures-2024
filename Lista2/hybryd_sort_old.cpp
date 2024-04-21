#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "ex1.hpp"

// Funkcja scalająca podciągi z maksymalną efektywnością.
void merge_Timsort(data *d, stats *s, int p, int q, int r)
{
    int *array = d->array;
    std::vector<int> leftSubarray(array + p, array + q + 1);      // Tworzenie lewego podciągu.
    std::vector<int> rightSubarray(array + q + 1, array + r + 1); // Tworzenie prawego podciągu.

    int i = 0, j = 0, k = p;

    while (i < leftSubarray.size() && j < rightSubarray.size())
    {
        s->compares++;
        if (leftSubarray[i] <= rightSubarray[j])
        {
            array[k] = leftSubarray[i];
            i++;
        }
        else
        {
            array[k] = rightSubarray[j];
            j++;
        }
        s->swaps++;
        k++;
    }

    while (i < leftSubarray.size())
    {
        array[k] = leftSubarray[i];
        i++;
        k++;
    }

    while (j < rightSubarray.size())
    {
        array[k] = rightSubarray[j];
        j++;
        k++;
    }
}

// Funkcja sortująca korzystająca z metody "dziel i zwyciężaj" i procedury scalania podciągów.
void hybryd_sort(data *d, stats *s, int p, int r)
{
    if (p < r)
    {
        if (r - p + 1 <= INSERTION_SORT_THRESHOLD)
        {
            insertion_sort(d, s); // Wywołanie sortowania przez wstawianie dla małych podtablic.
        }
        else
        {
            int q = (p + r) / 2;
            hybryd_sort(d, s, p, q);      // Sortowanie lewej połowy tablicy.
            hybryd_sort(d, s, q + 1, r);  // Sortowanie prawej połowy tablicy.
            merge_Timsort(d, s, p, q, r); // Scalenie posortowanych podciągów.
        }
    }
}