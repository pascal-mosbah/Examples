#include <cstdlib>
#include <cstring>
#include <iostream>
#include <chrono>

using namespace std;

template <typename T_>
void my_allocation(T_ *&ptr, const size_t &old_size, const size_t &new_size)
{
    static unsigned count = 1;
    if (ptr)
    {
        auto new_ptr = new T_[new_size];
        memcpy(new_ptr, ptr, old_size * sizeof(T_));
        delete[] ptr;
        ptr = new_ptr;
    }
    else
    {
        ptr = new T_[new_size];
    }
    ++count;
}

template <typename T_>
void my_allocation_using_C(T_ *&ptr, const size_t &new_size)
{
    static unsigned count = 1;
    if (ptr)
    {
        auto old_ptr = ptr;
        ptr = static_cast<T_ *>(realloc(ptr, new_size * sizeof(T_)));
        if (!ptr)
        {
            cout << "Bad allocation using malloc" << endl;
            exit(EXIT_FAILURE);
        }
        if (old_ptr != ptr)
        {
            cout << "Pointer address has changed at iteration : " << count << endl;
        }
    }
    else
    {
        ptr = static_cast<T_ *>(malloc(new_size * sizeof(T_)));
    }
    ++count;
}

int main()
{
    const size_t increment = 1 << 18;
    cout << increment << endl;
    float *tab_float = nullptr;
    float *tab_float_using_C = nullptr;
    size_t size = increment, initial_size = 0;

    try
    {
        for (auto i = 0; i < 100; ++i)
        {
            my_allocation(tab_float, initial_size, size);
            initial_size = size;
            size += increment;
        }
    }
    catch (const bad_alloc &e)
    {

        cout << "Memory Allocation"
             << e.what()
             << endl;
    }
    
    delete[] tab_float;

    size = 0;
    for (auto i = 0; i < 100; ++i)
    {
        my_allocation_using_C(tab_float_using_C, size);
        size += increment;
    }
}