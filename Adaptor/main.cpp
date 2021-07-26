#include <iostream>
#include <map>

template <typename T>
class multiset
{
private:
    std::map<T, T> m;
    std::map<T, unsigned> count;

public:
    void push(T a)
    {
        m[a] = a;

        if (!count[a])
        {
            std::cout << a << " " << count[a] << std::endl;
            count[a] = 1;
        }
        else
        {
            count[a]++;
        }
    }

    void print()
    {
        for (const auto &[key, value] : m)
        {
            for (int i = 1; i <= count[key]; i++)
                std::cout << value << ",";
        }
    }
};

int main()
{
    int arr[] = {2, 3, 6, 5, 2, 8, 6, 4, 3};
    multiset<int> m;

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        m.push(arr[i]);

    m.print();

    return 0;
}