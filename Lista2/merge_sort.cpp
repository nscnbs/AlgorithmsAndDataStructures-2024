// Lista 2 Illia Azler 239537

#include <iostream>
#include <cmath>
#include "ex1.hpp"

void merge_sort(data *d, stats *s, int p, int q)
{
    int mid; // Index of middle element.
    if (p < q)
    {
        mid = p + (q - p) / 2;        // Compute index of middle element.
        merge_sort(d, s, p, mid);     // Resursive merge sort of left half of array.
        merge_sort(d, s, mid + 1, q); // Recursive merge sort on right half of array.
        merge(d, s, p, mid, q);       // Merge sorted halfs of array (when every part of array has length 1).
    }
}

void merge(data *d, stats *s, int p, int mid, int q)
{
    int *array = d->array;
    int *temp = new int[d->length];
    std::string comparator = d->comparator;

    int i = 0;       // First element of temp array.
    int j = p;       // First element of 'left' array.
    int k = mid + 1; // First element of 'right' array.

    while (j <= mid && k <= q)
    { // Compare elements until 'left' or 'right' array isn't empty.
        // std::cerr << "Compare: " << array[j] << comparator << array[k] << std::endl;
        if (compare(comparator, array[j], array[k]))
        { // Take smaller element and put it to temp.
            // std::cerr << "Swap: " << array[j] << " <-> " << array[k] << std::endl;
            temp[i] = array[j];
            j++;
        }
        else
        {
            // std::cerr << "Swap: " << array[k] << " <-> " << array[j] << std::endl;
            temp[i] = array[k];
            k++;
        }
        i++;
        s->compares++;
        s->swaps++;
    }

    // Put elements to end of sorted array.
    while (j <= mid)
    {
        temp[i] = array[j];
        i++;
        j++;
        s->swaps++;
    }

    while (k <= q)
    {
        temp[i] = array[k];
        i++;
        k++;
        s->swaps++;
    }

    i = 0;
    for (int l = p; l <= q; l++)
    {
        array[l] = temp[i];
        i++;
    }

    delete[] temp;
}