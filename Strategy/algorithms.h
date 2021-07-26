#pragma once

template <typename T>
class searchAlgorithms
{
public:
    bool linearSearch(T arr[], T elem)
    {
        bool b = false;
        for (int i = 0; i < sizeof(arr) / sizeof(T); i++)
        {
            if (arr[i] == elem)
            {
                b = true;
                break;
            }
        }
        return (b);
    }

    bool binarySearch(T arr[], T elem)
    {
        bool b = false;
        int low = 0;
        int high = sizeof(arr) / sizeof(int) - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == elem)
            {
                b = true;
                break;
            }
            else if (arr[mid] < elem)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return (b);
    }
};

template <typename T>
class sortAlgorithms
{
public:
    void mergeSort(T arr[])
    {
    }

    void quickSort(T arr[])
    {
    }

    void insertionSort(T arr[])
    {
    }
};
