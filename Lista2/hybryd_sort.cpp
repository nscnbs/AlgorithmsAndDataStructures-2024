// Lista 2 Illia Azler 239537

#include <iostream>
#include <cmath>
#include "ex1.hpp"

void hybryd_sort(data *d, stats *s, int p, int q)
{
    int mid;
    int i;
    if (p < q)
    {
        if (q - p + 1 <= INSERTION_SORT_THRESHOLD)
        {
            insertion_sort(d, s);
        }
        else if (q - p + 1 <= QUICK_SORT_THRESHOLD)
        {
            i = partition(d, s, p, q);
            quick_sort(d, s, p, i - 1);
            quick_sort(d, s, i + 1, q);
        }
        else
        {
            mid = p + (q - p) / 2;
            merge_sort(d, s, p, mid);
            merge_sort(d, s, mid + 1, q);
            merge(d, s, p, mid, q);
        }
    }
}