#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T_>
void my_allocation(T_ *&ptr, const size_t &old_size, const size_t &new_size)
{
    static unsigned count = 1;
    if (ptr)
    {
        auto new_ptr = new T_[new_size];
        memcpy(new_ptr, ptr, old_size * sizeof(T_));
        if (new_ptr != ptr)
        {
            cout << "Pointer address has changed at iteration : " << count << endl;
        }
        delete[] ptr;
        ptr = new_ptr;
    }
    else
    {
        ptr = new T_[new_size];
    }
    ++count;
}

int main()
{
    const size_t size = 1 << 10;
    cout << size << endl;
    float *tab_float = nullptr;

    try
    {
        for (auto i = 0; i < 100; ++i)
        {
            my_allocation(tab_float, 0, size);
        }
    }
    catch (const bad_alloc &e)
    {

        cout << "Memory Allocation"
             << e.what()
             << endl;
    }
}