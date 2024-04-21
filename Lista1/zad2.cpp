// Autor: Illia Azler 239537

#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef struct Element element;
typedef struct List list;

struct Element
{
    int value;
    Element *next;
};
struct List
{
    Element *head;
    Element *tail;
    int size;
};

bool isEmpty(List *list)
{
    if (list->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

List *createList()
{
    List *list = new List;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void initList(List *list, int value)
{
    Element *element = new Element;
    element->value = value;
    element->next = NULL;
    list->head = element;
    list->tail = element;
    list->size = 1;
}

/**
 * Gdy lista jest pusta dodaje element
 * @param list
 * @param value
 */
void insert(List *list, int value)
{
    if (isEmpty(list))
    {
        initList(list, value);
        return;
    }

    Element *element = new Element;
    element->value = value;
    element->next = NULL;
    list->head->next = element;
    list->head = element;
    list->size++;
}

/**
 * Gdy index'u nie istnieje zwraca false
 * @param list
 * @param index
 * @return
 */
bool takeFromList(List *list, int index)
{
    if (index >= list->size)
    {
        return false;
    }

    Element *temp = list->tail;
    Element *prev = NULL;

    if (index == 0)
    {
        list->tail = list->tail->next;
    }
    else
    {
        for (int i = 1; i <= index; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
    }
    free(temp);
    list->size--;
    return true;
}

/**
 * Szukanie wartosci z indeksu
 * @param list
 * @param index
 * @return
 */
int find(List *list, int index)
{
    int licznik = 0;
    if (index >= list->size)
    {
        return -1;
    }

    Element *temp = list->tail;
    for (int i = 1; i <= index; i++)
    {
        temp = temp->next;
        licznik++;
    }
    // return temp->value;
    return licznik;
}

void showList(List *list)
{
    if (isEmpty(list))
    {
        printf("Pusta lista\n");
        return;
    }

    Element *temp = list->tail;
    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

List *merge(List *list1, List *list2)
{
    List *merged = createList();
    Element *temp = list1->tail;

    while (temp != NULL)
    {
        insert(merged, temp->value);
        temp = temp->next;
    }

    temp = list2->tail;

    while (temp != NULL)
    {
        insert(merged, temp->value);
        temp = temp->next;
    }

    return merged;
}

void test1()
{
    int k = 0;
    List *list1 = createList();
    for (int i = 0; i < 10; i++)
    {
        k = rand() % 99;
        insert(list1, k);
    }
    showList(list1);

    List *list2 = createList();
    for (int i = 0; i < 10; i++)
    {
        k = rand() % 99;
        insert(list2, k);
    }
    showList(list2);

    List *merged = merge(list1, list2);
    showList(merged);
}

void test2()
{
    int value;
    int index;
    double averageComparisonCost;
    int n = 1000; // Liczba wyszukiwań
    int totalComparisons = 0;
    int randomIndex = 0;
    int randomNumber = 0;

    List *test = createList();

    // Utwórz tablicę T zawierającą 10000 losowych liczb całkowitych z przedziału I = [0, ..., 100000]
    int T[10000];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        T[i] = rand() % 100001; // Losowa liczba całkowita z przedziału [0, 100000]
    }

    // Wstaw te liczby do listy L
    for (int i = 0; i < 10000; i++)
    {
        insert(test, T[i]);
    }

    // Wykonaj wyszukiwania losowych liczb z przedziału I na liście L
    for (int i = 0; i < n; i++)
    {
        randomIndex = rand() % 10000;                // Losowy indeks
        totalComparisons += find(test, randomIndex); // Dodaj ilość porównań
    }

    averageComparisonCost = (double)totalComparisons / n; // Średni koszt tysiąca wyszukiwań
    printf("Średni koszt tysiąca wyszukiwań dla liczb z T o losowych indeksiach: %f\n", averageComparisonCost);

    totalComparisons = 0;
    averageComparisonCost = 0;

    // Wykonaj wyszukiwania losowych liczb z zakresu I na liście L
    for (int i = 0; i < n; i++)
    {
        randomNumber = rand() % 100001;               // Losowa liczba całkowita z zakresu [0, 100000]
        totalComparisons += find(test, randomNumber); // Dodaj ilość porównań
    }

    averageComparisonCost = (double)totalComparisons / n; // Średni koszt tysiąca wyszukiwań
    printf("Średni koszt tysiąca wyszukiwań losowych liczb z zakresu [0, 100000] na liście: %f\n", averageComparisonCost);
}

int main()
{
    printf("Zadanie 2:\n");
    test1();
    test2();
    return 0;
}