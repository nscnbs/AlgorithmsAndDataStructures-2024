// Lista 2 Illia Azler 239537

#include <iostream>
#include <cstdbool>
#include "ex1.hpp"

void hybryd_quick_sort(data *d, stats *s, int p, int q)
{
    int i;

    if (p < q)
    {
        if (q - p + 1 <= INSERTION_SORT_THRESHOLD)
        {
            insertion_sort(d, s);
        }
        else
        {
            i = partition(d, s, p, q);
            quick_sort(d, s, p, i - 1);
            quick_sort(d, s, i + 1, q);
        }
    }
}