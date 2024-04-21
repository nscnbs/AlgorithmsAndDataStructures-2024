// Lista 2 Illia Azler 239537

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

#include "ex1.hpp"

void statistics(std::string *params)
{
    int *array;
    int *copy;
    int k;
    std::string type, file_name;
    data *d;
    stats *s;
    clock_t start, stop;

    int mid_swaps, mid_compares;
    double mid_time;
    // swaps_n, compares_n;

    type = params[1];
    file_name = params[2];

    std::istringstream(params[3]) >> k;

    std::ofstream fout;

    fout.open(file_name += ".log");

    // fout: n; compares; swaps; time;
    for (int i = 0; i < k; i++)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        // for (int n = 1000; n <= 50000; n += 1000) // other algortims
        for (int n = 10; n <= 50; n += 10) // insert
        {
            mid_compares = 0;
            mid_swaps = 0;
            mid_time = 0;
            // swaps_n = 0;
            // compares_n = 0;
            array = new int[n];
            copy = new int[n];
            new_array(array, n);
            copy_array(array, copy, n);

            d = new data;
            d->length = n;
            d->array = copy;
            d->comparator = params[0];

            s = new stats;
            s->compares = 0;
            s->swaps = 0;
            s->time = 0;

            if (type.compare("insert") == 0)
            {
                start = clock();
                insertion_sort(d, s);
                stop = clock();
            }
            else if (type.compare("merge") == 0)
            {
                start = clock();
                merge_sort(d, s, 0, n - 1);
                stop = clock();
            }
            else if (type.compare("quick") == 0)
            {
                start = clock();
                quick_sort(d, s, 0, n - 1);
                stop = clock();
            }
            else if (type.compare("dual") == 0)
            {
                start = clock();
                dual_pivot_quick_sort(d, s, 0, n - 1);
                stop = clock();
            }
            else if (type.compare("hybryd_quick") == 0)
            {
                start = clock();
                hybryd_quick_sort(d, s, 0, n - 1);
                stop = clock();
            }
            else if (type.compare("hybryd") == 0)
            {
                start = clock();
                hybryd_sort(d, s, 0, n - 1);
                stop = clock();
            }
            else
            {
                std::cout << "Invalid name of algorithm!" << std::endl;
            }

            s->time = (double)(stop - start) / CLOCKS_PER_SEC;

            mid_swaps += s->swaps;
            mid_compares += s->compares;
            mid_time += s->time;
            fout << n << " " << s->compares << " " << s->swaps << " " << s->time << "\n";

            delete[] copy;
            delete[] array;
            delete s;
            delete d;

            // swaps_n = (double)mid_swaps / n;
            // compares_n = (double)mid_compares / n;

            // mid_swaps = mid_swaps / k;
            // mid_compares = mid_compares / k;
            // mid_time = (double)mid_time / k;

            // fout << "\n"

            // fout << n << " " << mid_compares << " " << mid_swaps << " " << mid_time << "\n";
        }
    }
    fout << "";
    fout.close();
}

void new_array(int *array, int n)
{

    // srand(time(NULL));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 2 * n - 1);

    for (int i = 0; i < n; i++)
    {
        array[i] = dis(gen);
        // array[i] = rand() % (2 * n - 1);
    }
}

void copy_array(int *array, int *copy, int n)
{
    for (int i = 0; i < n; i++)
    {
        copy[i] = array[i];
    }
}
