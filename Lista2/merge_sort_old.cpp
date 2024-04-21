// Lista 2 Illia Azler 239537

#include <iostream>
#include <cmath>
#include "ex1.hpp"

void merge_old(data *d, stats *s, int const p, int const mid, int const q)
{
    int const subOne = mid - p + 1;
    int const subTwo = q - mid;

    int *left = new int[subOne];
    int *right = new int[subTwo];

    for (int i = 0; i < subOne; i++)
        left[i] = d->array[p + i];
    for (int j = 0; j < subTwo; j++)
        right[j] = d->array[mid + 1 + j];

    int idxSubOne = 0, idxSubTwo = 0;
    int idxMerged = p;

    while (idxSubOne < subOne && idxSubTwo < subTwo)
    {

        if (left[idxSubOne] <= right[idxSubTwo])
        {

            d->array[idxMerged] = left[idxSubOne];
            idxSubOne++;
        }
        else
        {

            d->array[idxMerged] = right[idxSubTwo];
            idxSubTwo++;
        }
        idxMerged++;
        s->compares++;
        s->swaps++;
    }

    while (idxSubOne < subOne)
    {
        d->array[idxMerged] = left[idxSubOne];
        idxSubOne++;
        idxMerged++;
        s->swaps++;
    }

    while (idxSubTwo < subTwo)
    {
        d->array[idxMerged] = right[idxSubTwo];
        idxSubTwo++;
        idxMerged++;
        s->swaps++;
    }

    delete[] left;
    delete[] right;
}

void merge_sort_old(data *d, stats *s, int const p, int const q)
{
    if (p >= q)
        return;

    int mid = p + (q - p) / 2;
    merge_sort_old(d, s, p, mid);
    merge_sort_old(d, s, mid + 1, q);
    merge_old(d, s, p, mid, q);
}
