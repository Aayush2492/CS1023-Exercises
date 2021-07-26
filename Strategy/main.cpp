/**
 * Implementing searching and sorting as strategies with class algorithm at top.
 * 
 */
#include <iostream>
#include "algorithms.h"

template <typename T>
class searching;

template <typename T>
class sorting;

template <typename T>
class algorithm
{
    searching<T> *srch;
    sorting<T> *srt;

public:
    void setSearch();
    void setSort();

    bool execute(int arr[], int elem)
    {
        bool b = srch->search(arr, elem);
        srt->sort(arr);
        return b;
    }
};

//Search strategy
template <typename T>
class searching
{
public:
    virtual ~searching(){};
    virtual bool search(T[], T) = 0;
};

//Sort strategy
template <typename T>
class sorting
{
public:
    virtual ~sorting(){};
    virtual void sort(T[]) = 0;
};

template <typename T>
class linear_search : public searching<T>
{
public:
    bool search(T arr[], T elem) override
    {
        searchAlgorithms<T> *obj = new searchAlgorithms<T>();
        return (obj->linearSearch(arr, elem));
    }
};

template <typename T>
class binary_search : public searching<T>
{
public:
    bool search(T arr[], T elem) override
    {
        sortAlgorithms<T> *obj = new sortAlgorithms<T>();
        obj->insertionSort(arr);

        searchAlgorithms<T> *obj2 = new searchAlgorithms<T>();
        return (obj2->binarySearch(arr, elem));
    }
};

template <typename T>
class merge_sort : public sorting<T>
{
public:
    void sort(T arr[]) override
    {
        sortAlgorithms<T> *obj = new sortAlgorithms<T>();
        obj->mergeSort(arr);
    }
};

template <typename T>
class insertion_sort : public sorting<T>
{
public:
    void sort(T arr[]) override
    {
        sortAlgorithms<T> *obj = new sortAlgorithms<T>();
        obj->insertionSort(arr);
    }
};

template <typename T>
class quick_sort : public sorting<T>
{
public:
    void sort(T arr[]) override
    {
        sortAlgorithms<T> *obj = new sortAlgorithms<T>();
        obj->quickSort(arr);
    }
};

template <typename T>
void algorithm<T>::setSearch()
{
    srch = new linear_search<T>();
}

template <typename T>
void algorithm<T>::setSort()
{
    srt = new quick_sort<T>();
}

int main()
{
    int arr[] = {1, 3, 6, -43, 89, 34, 12, 103, -67};

    int search_elem = 78;

    algorithm<int> *alg = new algorithm<int>();

    alg->setSearch();
    alg->setSort();

    bool ans = alg->execute(arr, search_elem);

    if (ans == true)
        std::cout << "Found" << std::endl;

    return 0;
}