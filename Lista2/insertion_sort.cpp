// Lista 2 Illia Azler 239537

#include <iostream>
#include "ex1.hpp"

void insertion_sort(data *d, stats *s)
{

    int length = d->length; // Length of array to sort.
    int *array = d->array;  // Pointer to array to sort.
    std::string comparator = d->comparator;

    int j;

    // Loop for all elements in array;
    for (int i = 0; i < length; i++)
    {
        j = i; // Index of next. element to insert;

        while (j > 0 && compare(comparator, array[j], array[j - 1]))
        {
            // std::cerr << "Compare : " << array[j] << comparator << array[j - 1] << std::endl;
            s->compares++;

            // std::cerr << "Swap : " << array[j - 1] << " <-> " << array[j] << std::endl;
            s->swaps++;
            swap(array, j - 1, j);

            j--;
        }
        if (j > 0)
        {
            // std::cerr << "Compare : " << array[j] << comparator << array[j - 1] << std::endl;
            s->compares++;
        }
    }
}