#include <iostream>
#include "even_customIterator.h"
#include <algorithm>

int main()
{
    int arr[] = {1, 3, 4, -1, 2};

    customDS<int> var;

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        var.push_value(arr[i]);
    }

    customDS_iterator<int> i;
    for (i = var.begin(); i != var.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
    /**
     * Prints 3  -1
     */

    return 0;
}