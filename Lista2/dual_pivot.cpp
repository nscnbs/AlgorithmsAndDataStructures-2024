// Lista 2 Illia Azler 239537

#include <iostream>
#include <ctime>

#include "ex1.hpp"

void dual_pivot_quick_sort(data *d, stats *s, int left, int right)
{
    int *array = d->array;
    std::string comparator = d->comparator;
    int p, q;
    int i, j, k;
    int x;
    int temp;
    int index_1, index_2;

    if (left >= right)
    {
        return;
    }

    srand(time(nullptr));

    for (int i = 0; i < 5; i++)
    {
        index_1 = left + rand() % (right - left);
        index_2 = left + rand() % (right - left);

        if (array[index_1] != array[index_2])
        {
            break;
        }
    }

    if (array[index_1] != array[index_2])
    {
        if (compare(comparator, array[index_1], array[index_2]))
        {
            s->compares++;
            swap(array, index_1, right);
            p = array[right];
            swap(array, index_2, left);
            q = array[left];
            s->swaps += 2;
        }
        else
        {
            s->compares++;
            swap(array, index_2, right);
            p = array[right];
            swap(array, index_1, left);
            q = array[left];

            s->swaps += 2;
        }
    }
    else
    {
        if (compare(comparator, array[right], array[left]))
        {
            s->compares++;
            p = array[right];
            q = array[left];
        }
        else
        {
            s->compares++;
            p = array[left];
            q = array[right];
        }
    }

    i = left + 1;
    j = i;
    k = right - 1;

    x = 0;

    while (j <= k)
    {
        if (x >= 0)
        {
            s->compares++;
            if (compare(comparator, array[j], p))
            {
                s->compares++;

                if (array[i] != array[j])
                {
                    s->swaps++;
                    swap(array, i, j);
                }
                i++;
                j++;
                x++;
            }
            else
            {
                s->compares++;
                if (compare(comparator, array[j], q))
                {
                    j++;
                }
                else
                {
                    if (array[j] != array[k])
                    {
                        s->swaps++;
                        swap(array, j, k);
                    }
                    k--;
                    x--;
                }
            }
        }
        else
        {
            s->compares++;
            if (!compare(comparator, array[k], q))
            {
                k--;
                x--;
            }
            else
            {
                s->compares++;
                if (compare(comparator, array[k], p))
                {
                    temp = array[k];
                    array[k] = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                    i++;
                    x++;
                }
                else
                {

                    if (array[j] != array[k])
                    {
                        s->swaps++;
                        swap(array, j, k);
                    }
                }
                j++;
            }
        }
    }
    array[left] = array[i - 1];
    array[i - 1] = p;
    array[right] = array[k + 1];
    array[k + 1] = q;

    dual_pivot_quick_sort(d, s, left, i - 2);
    dual_pivot_quick_sort(d, s, i, k);
    dual_pivot_quick_sort(d, s, k + 2, right);
}