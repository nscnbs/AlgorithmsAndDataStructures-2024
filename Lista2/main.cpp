// Lista 2 Illia Azler 239537

// g++ -o sortowanie main.cpp merge_sort.cpp quick_sort.cpp statistics.cpp insertion_sort.cpp dual_pivot.cpp parser.cpp hybryd_quick_sort.cpp hybryd_sort.cpp -std=c++11

// ./sortowanie --comp "<=" --type hybryd --stat hybryd-k-100-n-10-50 100

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>
#include <random>

#include "ex1.hpp"

int main(int argc, char *argv[])
{

    std::string *params; // Array with type of sorting and type of comparator.
    std::string type;    // Type of sorting algorithm.
    data *d;             // Struct with array and size of it.
    stats *s;            // struct withs statistics of sorting.
    clock_t start, stop; // Variables to measure time.

    params = parse_args(argc, argv);

    if (argc == 8)
    {
        statistics(params);
        return 0;
    }

    int n;      // Size of an array.
    int *array; // Array with numbers to sort.
    int *copy;  // Array with numbers to sort.

    int check = 0;

    // Read size of array from stdin.
    std::cout << "Input n" << std::endl;
    std::cin >> n;

    std::cout << "0 - wprowadz dane\n1 - dane losowe\n2 - malejaco\n3 - rosnaco" << std::endl;
    std::cin >> check;

    array = new int[n];

    copy = new int[n];

    if (check == 1)
    {
        // srand(time(NULL));

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 2 * n - 1);

        for (int i = 0; i < n; i++)
        {
            // array[i] = rand() % (2 * n - 1);
            array[i] = dis(gen);
            std::cout << array[i] << ' ';
        }
    }
    else if (check == 2)
    {
        for (int i = 0; i < n; i++)
        {
            array[i] = (2 * n - 1) - i;
            std::cout << array[i] << ' ';
        }
    }

    else if (check == 3)
    {
        for (int i = 0; i < n; i++)
        {
            array[i] = i + (2 * n - 1);
            std::cout << array[i] << ' ';
        }
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            // Read elements of array.
            std::cin >> array[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        copy[i] = array[i];
    }

    d = new data;
    d->length = n;
    d->array = array;
    d->comparator = params[0];

    s = new stats;
    s->compares = 0;
    s->swaps = 0;
    s->time = 0;

    type = params[1];

    if (type.compare("insert") == 0)
    {
        std::cout << "\nInsert Sort" << std::endl;
        start = clock();
        insertion_sort(d, s);
        stop = clock();
    }
    else if (type.compare("merge") == 0)
    {
        std::cout << "\nMerge Sort" << std::endl;
        start = clock();
        merge_sort(d, s, 0, n - 1);
        stop = clock();
    }
    else if (type.compare("quick") == 0)
    {
        std::cout << "\nQuick Sort" << std::endl;
        start = clock();
        quick_sort(d, s, 0, n - 1);
        stop = clock();
    }
    else if (type.compare("dual") == 0)
    {
        std::cout << "\nDual Pivot Sort" << std::endl;
        start = clock();
        dual_pivot_quick_sort(d, s, 0, n - 1);
        stop = clock();
    }
    else if (type.compare("hybryd_quick") == 0)
    {
        std::cout << "\nHybryd Insert-Quick Sort" << std::endl;
        start = clock();
        hybryd_quick_sort(d, s, 0, n - 1);
        stop = clock();
    }
    else if (type.compare("hybryd") == 0)
    {
        std::cout << "\nHybryd Sort" << std::endl;
        start = clock();
        hybryd_sort(d, s, 0, n - 1);
        stop = clock();
    }
    else
    {
        std::cout << "Invalid name of algorithm!" << std::endl;
    }

    s->time = (double)(stop - start) / CLOCKS_PER_SEC;

    std::cout << "\nInput: ";

    for (int i = 0; i < n; i++)
    {
        std::cout << copy[i] << ' ';
    }
    std::cout << "\nCompares: " << s->compares << std::endl;
    std::cout << "Swaps: " << s->swaps << std::endl;
    std::cout << "Time: " << s->time << " sec" << std::endl;

    if (is_sorted(d))
    {

        std::cout << "Array is sorted\nOutput: ";
        for (int i = 0; i < n; i++)
        {
            std::cout << array[i] << ' ';
        }
        std::cout << " " << std::endl;
    }
    else
    {
        std::cout << "Array is not correctly sorted!" << std::endl;
    }

    delete d;
    delete s;
    delete[] array;
    delete[] params;
    return 0;
}