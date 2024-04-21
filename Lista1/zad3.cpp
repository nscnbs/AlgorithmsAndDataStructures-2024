// Autor: Illia Azler 239537

#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef struct Element Element;
typedef struct List List;

struct Element
{
    int value;
    Element *next;
    Element *prev;
};

struct List
{
    int size;
    Element *head;
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
    list->size = 0;
    return list;
}

void initList(List *list, int value)
{
    Element *element = new Element;
    element->value = value;

    element->next = element;
    element->prev = element;
    list->head = element;
    list->size = 1;
}

void insert(List *list, int value)
{
    if (isEmpty(list))
    {
        initList(list, value);
        return;
    }
    Element *element = new Element;
    element->value = value;
    element->prev = list->head->prev;
    element->next = list->head;
    list->head->prev->next = element;
    list->head->prev = element;
    list->size++;
}

bool takeFromList(List *list, int index)
{
    if (index >= list->size)
    {
        return false;
    }

    Element *temp = list->head;
    ;

    if (index == 0)
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        list->head = temp->next;
        free(temp);
        list->size--;
        return true;
    }

    if (index < list->size / 2)
    {
        for (int i = 1; i <= index; i++)
        {
            temp = temp->next;
        }
    }
    else
    {
        int start = list->size - 1;
        for (int i = start; i >= index; i--)
        {
            temp = temp->prev;
        }
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;

    list->size--;
    free(temp);
    return true;
}

bool check(List *list, int value)
{
    Element *temp = list->head;
    int end = list->size;
    for (int i = 0; i < end; i++)
    {
        if (temp->value == value)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

int find(List *list, int index)
{
    int licznikForward = 0;
    int licznikBack = 0;
    int kierunek = rand() % 2; // 0 - do przodu, 1 - do tyłu

    if (index >= list->size)
    {
        return -1;
    }

    Element *temp;

    if (kierunek == 0)
    {
        temp = list->head;
        for (int i = 0; i < index && licznikForward <= 2 * index; i++)
        {
            temp = temp->next;
            licznikForward++;
        }
    }
    else
    {
        temp = list->head->prev;
        for (int i = 0; i < index && licznikBack <= 2 * index; i++)
        {
            temp = temp->prev;
            licznikBack++;
        }
    }

    return kierunek == 0 ? licznikForward : licznikBack;
}

void showList(List *list)
{
    if (isEmpty(list))
    {
        printf("Pusta lista\n");
        return;
    }

    Element *temp = list->head;
    int end = list->size;

    printf("(H) ");
    for (int i = 0; i < end; i++)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("%d (H)\n", list->head->value);
}

List *merge(List *list1, List *list2)
{
    List *merged = createList();

    Element *temp = list1->head;
    int end = list1->size;
    for (int i = 0; i < end; i++)
    {
        insert(merged, temp->value);
        temp = temp->next;
    }

    temp = list2->head;
    end = list2->size;

    for (int i = 0; i < end; i++)
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
    printf("Zadanie 3:\n");
    test1();
    test2();
    return 0;
}