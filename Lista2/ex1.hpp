/// Lista 2 Illia Azler 239537

typedef struct data data;
typedef struct stats stats;

struct data
{
    std::string comparator;
    int length;
    int *array;
};

struct stats
{
    int compares;
    int swaps;
    double time;
};

const int INSERTION_SORT_THRESHOLD = 20;
const int QUICK_SORT_THRESHOLD = 50;

std::string *parse_args(int argc, char **argv);

bool compare(std::string comparator, int a, int b);

bool is_sorted(data *d);

void merge_sort(data *d, stats *s, int p, int q);
void merge(data *d, stats *s, int p, int mid, int q);

void merge_sort_old(data *d, stats *s, int p, int q);
void merge_old(data *d, stats *s, int p, int mid, int q);

void insertion_sort(data *d, stats *s);

void quick_sort(data *d, stats *s, int p, int q);
int partition(data *d, stats *s, int p, int q);
void swap(int *array, int i, int j);

void statistics(std::string *params);
void new_array(int *array, int n);
void copy_array(int *array, int *copy, int n);

void dual_pivot_quick_sort(data *d, stats *s, int left, int right);
void dual_pivot_partition(data *d, stats *s);

void hybryd_quick_sort(data *d, stats *s, int p, int q);
void hybryd_merge(data *d, stats *s, int p, int mid, int q);
void hybryd_merge_sort(data *d, stats *s, int p, int q);

void hybryd_sort(data *d, stats *s, int p, int q);
void merge_Timsort(data *d, stats *s, int p, int q, int r);